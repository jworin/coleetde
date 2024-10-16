#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, ki;
    cin >> ki;
    while(ki--) {
        cin >> ni;
        vector<long long> v(ni);
        for (long long &i: v) {
            cin >> i;
        }
        for(long long i = 0; i < v.size(); ++i) {
            for(long long j = i + 1; j < v.size(); ++j) {
                if(v[j] == v[i] or abs(j - i) == abs(v[j] - v[i])) {
                    cout << "NO\n";
                    goto loop;
                }
            }
        }
        cout << "YES\n";
    loop:;

    }



    return 0;
}
