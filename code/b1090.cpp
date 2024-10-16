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
    long long ni, mi, ki, ai, bi;
    cin >> ni >> mi;
    unordered_map<long long, unordered_set<long long>> um;
    while(ni--){
        cin >> ai >> bi;
        um[ai].insert(bi);
        um[bi].insert(ai);
    }
    while(mi--){
        cin >> ki;
        unordered_set<long long> us;
        while(ki--){
            cin >> ai;
            us.insert(ai);
        }
        for(auto i: us){
            if(um.count(i)) {
                for(auto j: um[i]) {
                    if(us.count(j)) {
                        cout << "No" << endl;
                        goto loop;
                    }
                }
            }
        }
        cout << "Yes" << endl;
    loop:;
    }


    return 0;
}
