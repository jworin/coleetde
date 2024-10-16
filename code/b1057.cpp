#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include <bitset>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string si;
    getline(cin, si);
    long long sum = accumulate(si.begin(), si.end(), 0, [](long long a, char c) {
        return a + (isalpha(c) ? tolower(c) - 'a' + 1 : 0);
    });
    bitset<32> b(sum);
    cout << (sum == 0 ? 0: (long long)log2(sum) + 1 - b.count()) << " " << b.count();

    return 0;
}


