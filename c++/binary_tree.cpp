#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int parent;
    int sibling;
    int depth;
    int degree;
    int height;
    bool leaf;
    pair<int, int> child;
};

void search_height(int u, vector<Node> &tree) {
    if (tree[u].leaf) {
        tree[u].height = 0;
        return;
    }
    if (tree[u].child.first != -1) search_height(tree[u].child.first, tree);
    if (tree[u].child.second != -1) search_height(tree[u].child.second, tree);

    if (tree[u].child.first != -1 && tree[u].child.second != -1)tree[u].height = max(tree[tree[u].child.first].height + 1, tree[tree[u].child.second].height + 1);
    else if (tree[u].child.first != -1) tree[u].height = tree[tree[u].child.first].height + 1;
    else if (tree[u].child.second != -1) tree[u].height = tree[tree[u].child.second].height + 1;
}

void search_depth(int u, vector<Node> &tree) {
    if (tree[u].child.first == -1 && tree[u].child.second == -1) return;

    if (tree[u].child.first != -1 && tree[u].child.second != -1) {
        tree[tree[u].child.first].depth = tree[u].depth + 1;
        tree[tree[u].child.second].depth = tree[u].depth + 1;
        search_depth(tree[u].child.first, tree);
        search_depth(tree[u].child.second, tree);
    }
    else if (tree[u].child.first != -1) {
        tree[tree[u].child.first].depth = tree[u].depth + 1;
        search_depth(tree[u].child.first, tree);
    } else if (tree[u].child.second != -1) {
        tree[tree[u].child.second].depth = tree[u].depth + 1;
        search_depth(tree[u].child.second, tree);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n);
    for (int i = 0; i < n; i++) {
        tree[i].parent = -1;
        tree[i].degree = 0;
        tree[i].sibling = -1;
        tree[i].leaf = false;
        tree[i].child = make_pair(-1, -1);
    }
    for (int i = 0; i < n; i++) {
        int id;
        int left;
        int right;
        cin >> id >> left >> right;
        if (left != -1 && right != -1) {
            tree[id].degree = 2;
            tree[id].child = make_pair(left, right);
            tree[left].parent = id;
            tree[right].parent = id;
            tree[left].sibling = right;
            tree[right].sibling = left;
        } else if (left != -1) {
            tree[id].degree = 1;
            tree[id].child = make_pair(left, right);
            tree[left].parent = id;
            tree[left].sibling = right;
        } else if (right != -1) {
            tree[id].degree = 1;
            tree[id].child = make_pair(left, right);
            tree[right].parent = id;
            tree[right].sibling = left;
        }else {
            tree[id].leaf = true;
        }
    }
    int par = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == -1) par = i;
    }
    search_depth(par, tree);
    search_height(par, tree);

    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": ";
        cout << "parent = " << tree[i].parent << ", ";
        cout << "sibling = " << tree[i].sibling << ", ";
        cout << "degree = " << tree[i].degree << ", ";
        cout << "depth = " << tree[i].depth << ", ";
        cout << "height = " << tree[i].height << ", ";
        if (tree[i].parent == -1) cout << "root" << endl;
        else if (tree[i].child.first != -1 || tree[i].child.second != -1) cout << "internal node" << endl;
        else cout << "leaf" << endl;
    } 
}