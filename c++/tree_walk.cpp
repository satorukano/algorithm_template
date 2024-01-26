#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int parent;
    pair<int, int> child;
};

void dfs_preorder(int u, vector<Node> &tree, vector<int> &order){
    order.push_back(u);
    if (tree[u].child.first == -1 && tree[u].child.second == -1) return ;
    
    if (tree[u].child.first != -1) {
        dfs_preorder(tree[u].child.first, tree, order);    
    }
    if (tree[u].child.second != -1) {
        dfs_preorder(tree[u].child.second, tree, order);
    }
    
}

void dfs_postorder(int u, vector<Node> &tree, vector<int> &order){
    order.push_back(u);
    if (tree[u].child.first == -1 && tree[u].child.second == -1) return ;
    
    if (tree[u].child.second != -1) {
        dfs_postorder(tree[u].child.second, tree, order);    
    }
    if (tree[u].child.first != -1) {
        dfs_postorder(tree[u].child.first, tree, order);
    }
    
}

void dfs_inorder(int u, vector<Node> &tree, vector<int> &order){
    if (tree[u].child.first == -1 && tree[u].child.second == -1) {
        order.push_back(u);
        return ;
    }
    
    if (tree[u].child.first != -1) {
        dfs_inorder(tree[u].child.first, tree, order);    
    }
    order.push_back(u);
    if (tree[u].child.second != -1) {
        dfs_inorder(tree[u].child.second, tree, order);
    }
    
}



int main() {
    int n;
    cin >> n;
    vector<Node> tree(n);
    for (int i = 0; i < n; i++) {
        tree[i].parent = -1;
        tree[i].child = make_pair(-1, -1);
    }
    for (int i = 0; i < n; i++) {
        int id;
        int left;
        int right;
        cin >> id >> left >> right;
        if (left != -1 && right != -1) {
            tree[id].child = make_pair(left, right);
            tree[left].parent = id;
            tree[right].parent = id;
        } else if (left != -1) {
            tree[id].child = make_pair(left, right);
            tree[left].parent = id;
        } else if (right != -1) {
            tree[id].child = make_pair(left, right);
            tree[right].parent = id;
        }
    }
    int par = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i].parent == -1) par = i;
    }
    vector<int> pre_order;
    dfs_preorder(par, tree, pre_order);
    vector<int> post_order;
    dfs_postorder(par, tree, post_order);
    vector<int> in_order;
    dfs_inorder(par, tree, in_order);

    reverse(post_order.begin(), post_order.end());
    cout << "Preorder" << endl;
    for (int i = 0; i < n; i++) cout << ' ' <<pre_order.at(i);
    cout << endl;
    cout << "Inorder" << endl;
    for (int i = 0; i < n; i++) cout << ' ' << in_order.at(i);
    cout << endl;
    cout << "Postorder" << endl;
    for (int i = 0; i < in_order.size(); i++) cout << ' ' <<post_order.at(i);
    cout << endl;
    return 0;
}