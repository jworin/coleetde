#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;


const long long MAX = 1e5 + 5;
vector<vector<long long>> tree(MAX);
vector<double>price(MAX);
long long ni, ai, maxNum = 0;

double ri, pi, maxPrice = 0;
void dfs(long long root){
    if(price[root] > maxPrice){
        maxPrice = price[root];
        maxNum = 1;
    } else if(abs(maxPrice - price[root]) < 1e-6) {  // 判断double是否相等
        ++maxNum;
    }
    for(long long i: tree[root]){
        price[i] = price[root] * (1 + ri);
        dfs(i);
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ni >> pi >> ri;
    ri /= 100;
    long long root = -1;
    for(long long i = 0; i < ni; ++i){
        cin >> ai;
        if(ai == -1){
            root = i;
            price[i] = pi;
        } else {
            tree[ai].push_back(i);
        }
    }
    dfs(root);
    cout << fixed << setprecision(2) << maxPrice << " " << maxNum;

    return 0;
}
