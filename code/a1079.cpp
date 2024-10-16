#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;

const long long MAX = 1e5 + 5;
vector<vector<long long>> tree(MAX);
vector<double>amount(MAX), price(MAX);
long long ni, ki, ai;
double ri;

void dfs(long long root){
    for(long long i: tree[root]){
        price[i] = price[root] * (1 + ri);
        dfs(i);
    }
}

void bfs(long long root){
    queue<long long> q;
    q.push(root);
    while(not q.empty()){
        auto t = q.front();
        q.pop();
        for(auto i: tree[t]){
            q.push(i);
            price[i] = price[t] * (1 + ri);
        }
    }

}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ni >> price[0] >> ri;
    ri /= 100;
    for(long long i = 0; i < ni; ++i){
        cin >> ki;
        if(ki == 0){
            cin >> amount[i];
        }else {
            while(ki--){
                cin >> ai;
                tree[i].push_back(ai);
            }
        }
    }
    // dfs(0);
    bfs(0);
    cout << fixed << setprecision(1) << inner_product(price.begin(), price.begin() + ni, amount.begin(), 0.0);



    return 0;
}
