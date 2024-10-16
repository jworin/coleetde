#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
// 出现负数的时候要考虑输出会不会是-0.00
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ni;
    cin >> ni;
    long long sum = 0;
    for(long long i = 0; i < ni; ++i) {
        double cur;
        cin >> cur;
        sum += (i + 1) * (ni - i) * cur;
    }
    cout << fixed << setprecision(2) << sum;


    return 0;
}
