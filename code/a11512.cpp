#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

const long long no = INT_MAX + 111;
unordered_map<long long, long long> um;
long long LCA(vector<long long> &pre, long long r, long long left, long long right, long long p, long long q){
    if(left > right)
        return no;
    if(pre[r] == p or pre[r] == q)
        return pre[r];
    long long i = um[pre[r]];
    auto k1 = LCA(pre, r + 1, left, i - 1, p, q), k2 = LCA(pre, r + 1 + i - left, i + 1, right, p, q);
    return k1 == no? k2: k2 == no ? k1: pre[r];
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long mi, ni, u, v;
    cin >> mi >> ni;
    vector<long long> pre(ni);
    for(long long i = 0; i < ni; ++i){
        cin >> u;
        um[u] = i;
    }
    for(long long i = 0; i < ni; ++i)
        cin >> pre[i];

    while(mi--){
        cin >> u >> v;
        bool f1 = um.count(u), f2 = um.count(v);
        if(not f1 and not f2)
            cout << "ERROR: " << u << " and " << v <<" are not found." << endl;
        else if(not f1 or not f2){
            cout << "ERROR: " << (not f1? u: v) << " is not found." << endl;
        }else {
            long long ans = LCA(pre, 0, 0, ni - 1, u, v);
            if(ans == u or ans == v){
                cout << (ans == u ? u:v) << " is an ancestor of " << (ans == u? v: u) << "." << endl;
            }else {
                cout << "LCA of " << u << " and " << v << " is " << ans << "." << endl;
            }

        }
    }


    return 0;
}
