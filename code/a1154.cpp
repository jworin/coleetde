#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ni, mi, ki;
    cin >> ni >>  mi;
    vector<array<long long, 2>> edges(mi);
    for(auto & e: edges){
        cin >> e[0] >> e[1];
    }
    cin >> ki;
    vector<long long> colors(ni);
    while(ki--){
        unordered_set<long long> us;
        for(long long i = 0; i < ni; ++i){
            cin >> colors[i];
            us.insert(colors[i]);
        }
        for(auto & e:edges){
            if(colors[e[0]] == colors[e[1]]){
            cout << "No" << endl;
            goto loop;
                }
        }
        cout << us.size() << "-coloring" << endl;
    loop:;
    }


    return 0;
}
