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
    long long ni, mi, ki;
    cin >> ni >> mi;
    vector<vector<bool>> graph(ni + 1, vector<bool>(ni + 1));
    while(mi--){
        long long ai, bi;
        cin >> ai >> bi;
        graph[ai][bi] = graph[bi][ai] = true;
    }
    cin >> mi;
    while(mi--){
        bool ans = true;
        cin >> ki;
        vector<long long> v(ki);
        unordered_set<long long> us;
        for(long long & i: v){
            cin >> i;
            us.insert(i);
        }
        if(ki != ni + 1 or v[0] != v.back() or us.size() != ni){
            ans = false;
        }
        for(long long i = 0; i < ki - 1; ++i){
            if(not graph[v[i]][v[i + 1]]){
                ans = false;
            }
        }
        cout << (ans ? "YES": "NO") << "\n";


    }


    return 0;
}
