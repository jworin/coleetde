#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

struct BTNode {
    long long val;
    BTNode *left, *right;
    BTNode (long long v, BTNode *l = nullptr, BTNode *r = nullptr): val(v) {}
};

BTNode * buildBST(vector<long long> &pre, long long left, long long right){
    if(left > right){
        return nullptr;
    }
    long long i = find_if(pre.begin() + left, pre.begin() + right + 1, [&pre, left](int a){return a > pre[left];}) - pre.begin();
    auto root = new BTNode(pre[left]);
    root->left = buildBST(pre, left + 1, i - 1);
    root->right = buildBST(pre, i, right);
    return root;

}

BTNode * LCA(BTNode * root, long long p, long long q){
    return(root->val-p) * (root->val-q) <= 0 ? root:LCA(p<root->val?root->left:root->right, p, q);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long mi, ni, u, v;
    cin >> mi >> ni;
    vector<long long> pre(ni);

    for(long long i =0; i < ni; ++i)
        cin >> pre[i];
    auto root = buildBST(pre, 0, ni - 1);
    unordered_set<long long> us(pre.begin(), pre.end());
    while(mi--){
        cin >> u >> v;
        bool f1 = us.count(u), f2 = us.count(v);
        if(not f1 and not f2)
            cout << "ERROR: " << u << " and " << v <<" are not found." << endl;
        else if(not f1 or not f2){
            cout << "ERROR: " << (not f1? u: v) << " is not found." << endl;
        }else {
            long long ans = LCA(root, u, v)->val;
            if(ans == u or ans == v){
                cout << (ans == u ? u:v) << " is an ancestor of " << (ans == u? v: u) << "." << endl;
            }else {
                cout << "LCA of " << u << " and " << v << " is " << ans << "." << endl;
            }

        }
    }




    return 0;
}
