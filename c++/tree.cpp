#include <iostream>
#include <vector>
using namespace std;

struct Node {
    vector<int> child;
    int parent;
    int depth;
};

void search_depth(int u, vector<Node> &Tree) {
    if (Tree[u].child.size() == 0) return;

    for (int i = 0; i < Tree[u].child.size(); i++) {
        Tree[Tree[u].child[i]].depth = Tree[u].depth + 1;
        search_depth(Tree[u].child[i], Tree);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n);
    for (int i = 0; i < n; i++) {
        tree[i].parent = -1;
    }
    for (int i = 0; i < n; i++) {
        int id;
        int k;
        cin >> id;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int chl;
            cin >> chl;
            tree[id].child.push_back(chl);
            tree[chl].parent = id;
        }
    }
    int par = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == -1) par = i;
    }
    search_depth(par, tree);
    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": ";
        cout << "parent = " << tree[i].parent << ", ";
        cout << "depth = " << tree[i].depth << ", ";
        if (tree[i].parent == -1) cout << "root" << ", ";
        else if (tree[i].child.size() > 0) cout << "internal node" << ", ";
        else cout << "leaf" << ", ";
        cout << '[';
        for (int j = 0; j < tree[i].child.size(); j++) {
            if (j != tree[i].child.size() - 1) cout << tree[i].child[j] << ", ";
            else cout << tree[i].child[j];
        }
        cout << ']' << endl;
    } 
    return 0;
}
