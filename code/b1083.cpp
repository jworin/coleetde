#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, a;
    cin >> ni;
    map<long long, long long, greater<long long >> m;
    for(int i = 1; i <= ni; ++i) {
        cin >> a;
        ++m[abs(a - i)];
    }
    for(auto & i: m) {
        if(i.second > 1) {
            cout << i.first << " " << i.second << endl;
        }
    }

    return 0;
}
