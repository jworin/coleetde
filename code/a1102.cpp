#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

const long long MAXN = 15;
long long ni;
vector<array<long long, 2>>tree(MAXN, {-1, -1});

void inOrder(long long root, long long & n){
    if(root == -1)
        return;
    inOrder(tree[root][0], n);
    cout << root << (++n == ni? "\n": " ");
    inOrder(tree[root][1], n);
}

void levelOrder(long long root){
    queue<long long> q;
    q.push(root);
    long long n = 0;
    while(not q.empty()){
        auto t = q.front();
        q.pop();
        cout << t << (++n == ni? "\n": " ");
        if(tree[t][0] != -1)
            q.push(tree[t][0]);
        if(tree[t][1] != -1)
            q.push(tree[t][1]);
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ni;
    string s1, s2;
    vector<bool> f(ni);
    for(long long i = 0; i < ni; ++i){
        cin >> s1 >> s2;
        if(s1 != "-"){
            tree[i][1] = stoll(s1);
            f[stoll(s1)] = true;
        }
        if(s2 != "-"){
            tree[i][0] = stoll(s2);
            f[stoll(s2)] = true;
        }
    }
    long long root = find(f.begin(), f.end(), false) - f.begin();
    levelOrder(root);
    long long n = 0;
    inOrder(root, n);  // 这边的这个n不是关于第几层，而是统计一共输出了多少个

    return 0;
}
