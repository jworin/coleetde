#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, long long> um;
string s1, s2;
long long tag, radix;

long long rToDec(const string & r, long long R) {
    long long d = 0;
    for(auto i : r) {
        d = d * R + um[i];
    }
    return d;
}

long long binarySearchF(long long left, long long right, long long n) {
    while(left < right) {
        long long mid = (left + right) / 2;
        auto k = rToDec(s2, mid);
        if(k >= n or k < 0) {
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    auto k = rToDec(s2, left);
    return left > right or not (k >= n or k < 0) ? -1: left;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2 >> tag >> radix;
    if(tag == 2)
        swap(s1, s2);
    for(long long i = 0; i < 36; ++i){
        um.insert({i < 10 ? i + '0': i - 10 + 'a', i});
    }
    long long n = rToDec(s1, radix);
    auto m = max_element(s2.begin(), s2.end(), [](char c1, char c2){return um[c1] < um[c2];});
    long long left = um[*m] + 1;
    auto ans = binarySearchF(left, n + 1, n);
    ans == -1 or rToDec(s2, ans) != n ? cout << "Impossible" : cout << ans;

    return 0;
}
