#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<ll> pq;

void max_heapify(int idx) {
    int size = pq.size();
    int left = 2 * idx;
    int right = 2 * idx + 1;
    int largest = idx;
    if (left < size && pq[left] > pq[idx]) largest = left;
    if (right < size && pq[right] > pq[largest]) largest = right;

    if (largest != idx) {
        swap(pq[idx], pq[largest]);
        max_heapify(largest);
    }
}

void bubble_up(int idx) {
    while (idx > 1 && pq[idx / 2] < pq[idx]) {
        swap(pq[idx], pq[idx / 2]);
        idx /= 2;
    }
}

void insert(ll key) {
    pq.push_back(key);
    int idx = pq.size() - 1;
    bubble_up(idx);
}

ll extract_max() {
    if (pq.size() < 2) return -1;
    int size = pq.size();
    swap(pq[1], pq[size - 1]);
    ll max = pq.back();
    pq.pop_back();
    max_heapify(1);
    return max;
}


int main() {
    string s;
    int n;
    pq.push_back(-1);
    while(s != "end") {
        cin >> s;
        if (s == "end") break;
        if (s[0] == 'i') {
            cin >> n;
            insert(n);
        }else {
            ll max = extract_max();
            cout << max << endl;
        }
    }

    return 0;
}