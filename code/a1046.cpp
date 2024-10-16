#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, mi, sum = 0;
    cin >> ni;
    vector<long long> v(ni + 1);
    for(long long i = 1; i <= ni; ++i) {
        cin >> v[i];
    }
    partial_sum(v.begin(), v.end(), v.begin());
    cin >> mi;
    while(mi--) {
        long long ai, bi;
        cin >> ai >> bi;
        long long t = v[max(ai, bi) - 1] - v[min(ai, bi) - 1];
        cout << min(t, v.back() - t) << endl;
    }


    return 0;
}




/*

5

D1  D2  D3  D4  D5

*/

