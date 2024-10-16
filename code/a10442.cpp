#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <array>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ni, mi;
    cin >> ni >> mi;
    vector<long long > v(ni);
    for(long long & i: v) {
        cin >> i;
    }
    long long s = 0, sum = INT_MAX;
    vector<array<long long, 2>> ans;
    for(long long i = 0, j = 0; i < ni and j <= ni;) {
        if(s >= mi) {
            if(sum > s) {
                sum = s;
                ans = {{i + 1, j}};
            }else if(s == sum) {
                ans.push_back({i + 1, j});
            }
            s -= v[i++];
        } else {
            s += v[j++];
        }
    }
    for(auto & i: ans) {
        cout << i[0] << "-" << i[1] << endl;
    }

    return 0;
}


