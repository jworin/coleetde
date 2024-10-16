#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string si, out = "PATest";

    unordered_map<char, long long> um;
    cin >> si;
    for(char &c: si) {
        if(out.find(c) != -1) {
            ++um[c];
        }
    }
    while(not um.empty()) {
        for(char c: out) {
            if(um.count(c)) {
                cout << c;
                if (--um[c] == 0) {
                    um.erase(c);
                }
            }
        }
    }


    return 0;
}
