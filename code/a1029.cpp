#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <climits>
#include <iomanip>
#include <queue>
using namespace std;



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;
    vector<long long> s1(ni);
    for(long long &i: s1){
        cin >> i;
    }
    cin >> ni;
    vector<long long> s2(ni);
    for(long long &i: s2){
        cin >> i;
    }
    long long k = (s1.size() + s2.size() + 1) / 2, ans;
    for(long long i = 0, j = 0; k > 0; --k){
        long long a = i < s1.size() ? s1[i]: INT_MAX;
        long long b = j < s2.size() ? s2[j]: INT_MAX;
        if(a < b){
            ans = s1[i++];
        }else{
            ans = s2[j++];
        }
    }
    cout << ans;


    return 0;
}



