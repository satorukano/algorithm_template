#include <iostream>
#include <vector>
using namespace std;

vector<int> selection_sort(vector<int> vec) {
    int N = vec.size();
    for (int i = 0; i < N; i++) {
        int minimum_idx = i;
        for (int j = i + 1; j < N; j++) {
            if (vec.at(minimum_idx) > vec.at(j)) {
                minimum_idx = j;
            }
        }
        if (i != minimum_idx) {
            int minimum = vec.at(minimum_idx);
            int swapped_target = vec.at(i);
            vec.at(i) = minimum;
            vec.at(minimum_idx) = swapped_target;
        }
    }

    return vec;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    vector<int> sorted_vec(N);
    sorted_vec = selection_sort(A);
    for (int i = 0; i < N; i++) {
        if (i < N-1) cout << sorted_vec.at(i) << ' ';
        else cout << sorted_vec.at(i) << endl;
    }
    return 0;
}