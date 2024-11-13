#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

struct BTNode{
    long long val;
    BTNode *left, *right;
    BTNode(long long v, BTNode * l=nullptr, BTNode *r = nullptr): val(v) {}
};

BTNode * LCA(BTNode * root, BTNode *p, BTNode *q){
    if(not root)
        return nullptr;
    if(root == p or root == q)
        return root;
    BTNode * left = LCA(root->left, p, q), *right = LCA(root->right, p, q);
    if(not left and not right)
        return nullptr;
    if(not left)
        return right;
    if(not right)
        return left;
    return root;
}

BTNode * LCA2(BTNode * root, BTNode *p, BTNode *q){
    if(not root or root == p or root == q)
        return root;
    BTNode *left = LCA2(root->left, p, q), *right = LCA2(root->right, p, q);
    return not left? right: not right? left: root;
}

BTNode * LCA3(BTNode * root, long long p, long long q){
    if(not root or root->val == p or root->val == q)
        return root;
    BTNode *left = LCA3(root->left, p, q), *right = LCA3(root->right, p, q);
    return not left? right: not right? left: root;
}

BTNode * buildTree(vector<long long> &pre, vector<long long> &in, long long r, long long left, long long right){
    if(left > right)
        return nullptr;
    long long i = find(in.begin(), in.end(), pre[r]) - in.begin();
    auto root = new BTNode(pre[r]);
    root->left = buildTree(pre, in, r + 1, left, i - 1);
    root->right = buildTree(pre, in, r + 1 + i - left, i + 1, right);
    return root;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long mi, ni, u, v;
    cin >> mi >> ni;
    vector<long long> pre(ni), in(ni);
    for(long long i = 0; i < ni; ++i)
        cin >> in[i];
    for(long long i = 0; i < ni; ++i)
        cin >> pre[i];
    auto root = buildTree(pre, in, 0, 0, ni - 1);
    unordered_set<long long> us(in.begin(), in.end());
    while(mi--){
        cin >> u >> v;
        bool f1 = us.count(u), f2 = us.count(v);
        if(not f1 and not f2)
            cout << "ERROR: " << u << " and " << v <<" are not found." << endl;
        else if(not f1 or not f2){
            cout << "ERROR: " << (not f1? u: v) << " is not found." << endl;
        }else {
            long long ans = LCA3(root, u, v)->val;
            if(ans == u or ans == v){
                cout << (ans == u ? u:v) << " is an ancestor of " << (ans == u? v: u) << "." << endl;
            }else {
                cout << "LCA of " << u << " and " << v << " is " << ans << "." << endl;
            }

        }
    }


    return 0;
}
