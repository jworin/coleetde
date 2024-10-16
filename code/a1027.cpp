#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t = "0123456789ABC";
    cout << "#";
    for(long long i = 0; i < 3; ++i){
        long long ai;
        cin >> ai;
        cout << t[ai / 13] << t[ai % 13];
    }
    cout << endl;


    return 0;
}
