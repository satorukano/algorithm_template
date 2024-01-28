#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    ll key;
};

Node *root;
Node *NIL;




void insert(ll k) {
    Node *x, *y, *z;
    z = new Node;
    z->key = k;
    z->left = NIL;
    z->right = NIL;
    y = NIL;
    x = root;

    while(x != NIL) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }

    z->parent = y;
    if (y == NIL) root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}


Node* find(ll u) {
    Node* x = root;
    while (x != NIL) {
        if (x->key < u) x = x->right;
        else if (x->key > u) x = x->left;
        else return x;
    }

    return NIL;
    
}

void transplant(Node *u, Node *v) {
    if (u->parent == NIL) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NIL) {
        v->parent = u->parent;
    }
}

Node* tree_minimum(Node *x) {
    while (x->left != NIL) {
        x = x->left;
    }
    return x;
}

void delete_node(ll key) {
    Node* z = find(key);
    if (z == NIL) return; // Node not found

    if (z->left == NIL) {
        transplant(z, z->right);
    } else if (z->right == NIL) {
        transplant(z, z->left);
    } else {
        Node *y = tree_minimum(z->right);
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }

    delete z;
}


void pre_order(Node* u) {
    if (u == NIL) return;
    cout << ' ' << u->key;
    if (u->left != NIL) pre_order(u->left);
    if (u->right != NIL) pre_order(u->right);
}

void in_order(Node* u) {
    if (u == NIL) return;
    if (u->left != NIL) in_order(u->left);
    cout << ' ' <<u->key;
    if (u->right != NIL) in_order(u->right);
}


int main() {
    ll n;
    cin >> n;
    root = NIL;
    for (ll i = 0; i < n; i++) {
        string s;
        ll a;
        cin >> s;
        if (s == "insert") {
            cin >> a;
            insert(a);
        } else if (s == "find") {
            cin >> a;
            if (find(a) != NIL) {
                cout << "yes" << endl;
            }else {
                cout << "no" << endl;
            }
        }else if (s == "delete") {
            cin >> a;
            delete_node(a);
        }else{
            in_order(root);
            cout << endl;
            pre_order(root);
            cout << endl;
        }
    }
    return 0;
}