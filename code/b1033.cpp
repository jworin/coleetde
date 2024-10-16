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

    vector<bool> h(128);
    for(char c: s1){
        h[tolower(c)] = true;
    }
    for(char c:s2){
        if(h[tolower(c)] or (isupper(c) and h['+']))
            continue;
        cout << c;
    }
    cout << endl;

    return 0;
}
