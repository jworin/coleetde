#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
#include <unordered_set>
using namespace std;



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ni, mi, ki, ti, ai;
    cin >> ni >> mi;
    vector<array<long long, 2>> edges(mi);
    for(auto & e: edges){
        cin >> e[0] >> e[1];
    }
    cin >> ki;
    while(ki--){
        cin >> ti;
        unordered_set<long long> us;
        while(ti--){
            cin >> ai;
            us.insert(ai);
        }
        for(auto & e:edges){
            if(not us.count(e[0]) and not us.count(e[1])){
                cout << "No" << endl;
                goto loop;
            }
        }
        cout << "Yes" << endl;
    loop:;
    }

    return 0;
}
