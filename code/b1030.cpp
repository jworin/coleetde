
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ni, pi, ans = 0;
    cin >> ni >> pi;
    vector<long long> v(ni);
    for(long long i = 0; i < ni; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(long long i = 0; i < ni; ++i){
        ans = max(ans, upper_bound(v.begin(), v.end(), v[i] * pi) - v.begin() - i);
    }
    cout << ans;


    return 0;
}


