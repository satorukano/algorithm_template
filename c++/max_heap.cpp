#include <iostream>
#include <vector>
using namespace std;
using ll = long long;


ll H;
vector<ll> heap;

void max_heapify(ll idx) {
    if (idx > H/2) return ;
    ll left = idx * 2;
    ll right;
    if (idx * 2 == H) right = 0;
    else right = idx * 2 + 1;
    ll largest = idx;
    if (heap[left] >= heap[largest]) largest = left;

    if (heap[right] >= heap[largest]) largest = right;

    if (largest != idx) {
        swap(heap[idx], heap[largest]);
        max_heapify(largest);
    }
}
int main() {
    cin >> H;
    heap.resize(H+1);
    for (ll i = 1; i <= H; i++) cin >> heap.at(i);
    heap[0] = -3000000000ll;
    for (ll i = H/2; i > 0; i--) max_heapify(i);

    for (ll i = 1; i <= H; i++) cout << ' ' << heap[i];
    cout << endl;
}