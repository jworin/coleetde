#include <array>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    array<long long, 128> h{};
    for(char c: s1)
        ++h[c];
    for(char c: s2)
        --h[c];

    long long k1 = 0, k2 = 0;
    for(int i: h){
        i > 0 ? k1 += i: k2 -= i;
    }
    k2 > 0? cout << "No " << k2 : cout << "Yes " << k1;

    return 0;
}
