#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    vector<bool> h(128);
    for(char c: s2){
        h[c] = true;
    }
    for(char c: s1){
        if(not h[c]){
            cout << (char)toupper(c);
            h[c] = true;
        }
    }


    return 0;
}
