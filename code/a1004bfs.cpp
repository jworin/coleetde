#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

vector<vector<long long>> tree(105);
long long ni, mi, ki;

void levelOrder(long long root){
    queue<long long> q;
    q.push(root);
    bool space = false;
    while(not q.empty()){
        long long s = q.size(), ans = 0;
        while(s--){
            auto t = q.front();
            q.pop();
            if(tree[t].empty()){
                ++ans;
            }
            for(auto i: tree[t]){
                q.push(i);
            }
        }
        cout << (space?" ": "") << ans;
        space = true;
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ni >> mi;
    long long id1, id2;
    while(mi--){
        cin >> id1 >> ki;
        while(ki--){
            cin >> id2;
            tree[id1].push_back(id2);
        }
    }
    levelOrder(1);

    return 0;
}
