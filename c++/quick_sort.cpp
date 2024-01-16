#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<int> &vec, int left, int right) {
    if (right - left <= 1) return ;

    int pivot_index = (left + right) / 2;
    int pivot = vec[pivot_index];
    swap(vec[pivot_index], vec[right - 1]);
    int partition = left;
    for (int j = left; j < right; j++) {
        if (vec[j] < pivot) {
            swap(vec[partition], vec[j]);
            partition++;
        }
    }
    swap(vec[partition], vec[right-1]);
    cout << endl;
    quick_sort(vec, left, partition);
    quick_sort(vec, partition+1, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A.at(i);
    quick_sort(A, 0, n);
    for (int i = 0; i < n; i++) cout << A.at(i) <<' ';
    return 0;
}