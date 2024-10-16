#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>
#include<cmath>
using namespace std;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long ni, mi;
    cin >> ni >> mi;
    for(long long i = 0; i < ni; ++i) {
        long long g1, a;
        vector<long long> g2;
        cin >> g1;
        for(long long j = 0; j < ni - 1; ++j) {
            cin >> a;
            if(a >= 0 and a <= mi) {
                g2.push_back(a);
            }
        }
        auto m = minmax_element(g2.begin(), g2.end());
        long long g2a = accumulate(g2.begin(), g2.end(), 0) - *m.first - *m.second;
        // cout << round((g1 + g2a) * 1.0 / (g2.size() - 2 + 1)) << endl;
        cout << round((g1 + g2a * 1.0 / (g2.size() - 2)) / 2.0) << endl;
    }




    return 0;
}
