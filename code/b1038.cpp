#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<long long, 105> h{};
    long long n, a;
    cin >> n;
    while(n--){
        cin >> a;
        ++h[a];
    }
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        cout << (i == 0 ? "": " ") << h[a];
    }

    return 0;
}


