#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;
    while(ni--) {
        string si;
        cin >> si;
        unordered_map<char, long long> um;
        for(char c: si){
            ++um[c];
        }
        long long p = si.find('P'), t = si.find('T');
        if(um.size() == 3 and um['P'] == 1 and um['T'] == 1
            and um.count('A') > 0 and p < t - 1 and p * (t - p - 1) == si.size() - t - 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
