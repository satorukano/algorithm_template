#include <iostream>
#include <vector>
using namespace std;

vector<int> insertion_sort(vector<int> A) {
    int N = A.size();
    for (int i = 1; i < N; i++) {
        int target = A.at(i);
        int insert_idx = i - 1;
        while(insert_idx >= 0 && target < A.at(insert_idx)) {
            A.at(insert_idx + 1) = A.at(insert_idx);
            insert_idx--;
        } 
        A.at(insert_idx + 1) = target;
    }
    return A;
}

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec.at(i);
    vector<int> sorted_vec(N);
    sorted_vec = insertion_sort(vec);
    for (int i = 0; i < N; i++) {
        cout << sorted_vec.at(i) << ' ';
    }
    return 0;
}