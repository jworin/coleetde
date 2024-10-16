#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, ai;
    unordered_set<long long> us;
    cin >> ni;
    vector<long long> v;
    while(ni--) {
        cin >> ai;
        v.push_back(ai);
        while(ai != 1){
            if(ai % 2 == 1)
                ai = ai * 3 + 1;
            ai /= 2;
            us.insert(ai);
        }
    }
    sort(v.begin(), v.end(), greater<long long>());
    bool first = true;
    for(auto i: v){
        if(not us.count(i)) {
            cout << (first ? "": " ") << i;
            first = false;
        }
    }



    return 0;
}
