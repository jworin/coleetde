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
    for(long long i = 0, j = 0; j < v.size(); ++i) {
        while(j < v.size() and v[j] <= v[i] * pi){
            ++j;
        }
        ans = max(ans, j - i);
    }
    cout << ans;


    return 0;
}
