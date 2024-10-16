#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <climits>
#include <array>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, mi;
    cin >> ni >> mi;
    vector<long long> v(ni + 1);
    for(long long i = 1; i <= ni; ++i){
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), v.begin());
    long long sum = INT_MAX;
    vector<array<long long, 2>> ans;
    for(long long i = 0; i < v.size(); ++i){
        long long j = lower_bound(v.begin(), v.end(), v[i] + mi) - v.begin();
        if(j == v.size()) {
            continue;
        }
        long long s = v[j] - v[i];
        if(sum > s) {
            sum = s;
            ans = {{i + 1, j}};
        } else if(s == sum) {
            ans.push_back({i + 1, j});
        }
    }
    for(auto & i: ans){
        cout << i[0] << "-" << i[1] << endl;
    }

    return 0;
}
