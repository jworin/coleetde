#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long g1, s1, k1, g2, s2, k2;
    char c;
    cin >> g1 >> c >> s1 >> c >>k1 >> g2 >> c >> s2 >> c >> k2;
    long long t1 = (g1 * 17 + s1) * 29 + k1;
    long long t2 = (g2 * 17 + s2) * 29 + k2;
    t2 -= t1;
    cout << t2 / 29 / 17 << "." << abs(t2) / 29 % 17 << "." << abs(t2) % 29;
    return 0;

}
