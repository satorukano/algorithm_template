#include <iostream>
#include <vector>
using namespace std;

void merge_sort(vector<int> &vec, int left, int right) {
    if (right - left == 1) return;

    int mid = (left + right) / 2;

    merge_sort(vec, left, mid);
    merge_sort(vec, mid, right);

    vector<int> buf;
    for (int i = left; i < mid; i++) buf.push_back(vec[i]);
    for (int i = right- 1; i >= mid; i--) buf.push_back(vec[i]);

    int index_left = 0;
    int index_right = buf.size() - 1;
    for (int i = left; i < right; i++) {
        if (buf[index_left] <= buf[index_right]) {
            vec[i] = buf[index_left];
            index_left++;
        }else {
            vec[i] = buf[index_right];
            index_right--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    int ans = 0;
    merge_sort(a, 0, n);
    for (int i = 0; i < n; i++) {
        if (i != n-1) cout << a.at(i) << " ";
        else cout << a.at(i);
    }
    cout << endl;
    cout << ans << endl;
}