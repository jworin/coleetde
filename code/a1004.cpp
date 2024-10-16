#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

vector<vector<long long>> tree(105);
long long ni, mi, ki;
vector<long long> ans;
void preOrder(long long root, long long depth){
    if(ans.size() <= depth) {
        ans.push_back(0);
    }
    if(tree[root].empty()){
        ++ans[depth];
    }
    for(auto i: tree[root]){
        preOrder(i, depth + 1);
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
    preOrder(1, 0);
    for(long long i = 0; i < ans.size(); ++i){
        cout << (i==0? "": " ") << ans[i];
    }

    return 0;
}
