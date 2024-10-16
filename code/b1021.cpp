#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<long long, 10> h{};
    string s;
    cin >> s;
    for(char c: s){
        ++h[c - '0'];
    }
    for(int i = 0; i < h.size(); ++i){
        if(h[i] > 0){
            cout << i << ":" << h[i] << endl;
        }
    }

    return 0;
}
