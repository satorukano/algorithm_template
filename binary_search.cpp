#include<iostream>
#include<vector>
using namespace std;

bool P(int x) {
    // 条件を判定
}

long long binary_search(vector<long long> sorted_vector) {
    long long left = 0ll;
    long long right = (long long)sorted_vector.size();
    while(right - left < 1) {
        if (P(right)) left = (left + right) / 2ll;
        else right = (left + right) / 2ll;
    }
    return right;
}