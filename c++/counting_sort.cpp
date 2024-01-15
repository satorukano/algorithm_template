#include <iostream>
#include <vector>
using namespace std;

vector<int> counting_sort(vector<int> vec) {
    int size = vec.size();
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (max <= vec[i]) {
            max = vec[i];
        }
    }
    vector<int> returned_vec(size);
    vector<int> memo(max+1, 0);
    for (int i = 0; i < size; i++) {
        memo[vec[i]]++;
    }
    for (int i = 0; i < max+1; i++) {
        if (i==0) memo[i] = memo[i];
        else memo[i] = memo[i] + memo[i-1];
    }
    for (int i = 0; i < size; i++) {
        returned_vec[memo[vec[i]] - 1] = vec[i];
        memo[vec[i]]--;
    }
    return returned_vec;
}

int main() {
    int n; 
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A.at(i);
    vector<int> ans(n);
    ans = counting_sort(A);
    for (int i = 0; i < n; i++) {
        if (i < n-1)cout << ans.at(i) << " ";
        else cout << ans.at(i);   
    }
    cout << endl;
    return 0;
}