#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<string> s;
    string str;
    while(cin >> str) {
        s.push(str);
    }
    while(not s.empty()) {
        cout << s.top();
        s.pop();
        cout << (s.empty() ? "" : " ");
    }



    return 0;
}
