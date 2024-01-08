#include <iostream>
#include <vector>
using namespace std;

vector<int> bubble_sort(vector<int> vec) {
    int N = vec.size();
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j > i; j--) {
            int target = vec.at(j);
            int target_compared = vec.at(j-1);
            if (target < target_compared) {
                vec.at(j) = target_compared;
                vec.at(j-1) = target;
            }
        } 
    }
    return vec;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> ans(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    ans = bubble_sort(A);
    for (int i = 0; i < N; i++) {
        cout << ans.at(i) << ' ';
    }
}