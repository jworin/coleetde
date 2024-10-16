#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<long long, long long> um;
    long long ni, ai, bi;
    cin >> ni;
    while(ni--){
        cin >> ai >> bi;
        um[ai] = bi;
        um[bi] = ai;
    }
    cin >> ni;
    set<long long> s;
    while(ni--) {
        cin >> ai;
        if(not um.count(ai) or not s.count(um[ai])) {
            s.insert(ai);
        } else {
            s.erase(um[ai]);
        }
    }
    cout << s.size() << endl << setfill('0');
    for(auto i = s.begin(); i != s.end(); ++i){
        cout << (i == s.begin() ? "": " ") << setw(5) << *i;
    }


    return 0;
}
