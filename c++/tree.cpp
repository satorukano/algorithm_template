#include <iostream>
#include <vector>
using namespace std;

struct Node {
    vector<int> child;
    int parent;
};

int depth(int u, vector<Node> Tree, vector<int> &dep) {
    int parent = Tree[u].parent;
    int depth = 0;
    if (dep[parent] != -1 && parent != -1) return dep[parent] + 1;
    else {
        while (parent != -1) {
            parent = Tree[parent].parent;
            depth++;
        }
        dep[u] = depth;
        return depth;
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
    vector<int> dep(n, -1);
    for (int i = 0; i < n; i++) {
        cout << "node " << i << ": ";
        cout << "parent = " << tree[i].parent << ", ";
        cout << "depth = " << depth(i, tree, dep) << ", ";
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
