#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> tree(n+1);
    for (ll i = 1; i <= n; i++) cin >> tree.at(i);
    for (ll i = 1; i <= n; i++) {
        cout << "node " << i << ':' << " key = " << tree[i] << ", ";
        if (i != 1) {
            cout << "parent key = " << tree[i/2] << ", ";
        }

        if (n >= 2*i) {
            cout << "left key = " << tree[2*i] << ", ";
        }


        if (n >= 2*i+1) {
            cout << "right key = " << tree[2*i+1] << ",";
        }

        cout << endl;
    }
}