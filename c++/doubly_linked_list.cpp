using namespace std;

struct Node {
    Node *prev, *next;
    int key;
};

Node *nil;

void init() {
    nil = new Node();
    nil->next = nil;
    nil->prev = nil;
}

void insert(Node* v, Node* p) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p; 
}

void erase(Node* v) {
    if (v == nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
}