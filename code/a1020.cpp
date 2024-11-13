#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;

struct BTNode {
    long long val;
    BTNode *left = nullptr, *right = nullptr;
    BTNode(long long v, BTNode *l = nullptr, BTNode *r = nullptr): val(v) {}
};

BTNode * buildTree(vector<long long> &post, vector<long long> &in, long long r, long long left, long long right){
    if(left > right)
        return nullptr;
    long long i = find(in.begin(), in.end(), post[r]) - in.begin();
    auto root = new BTNode(post[r]);
    root->left = buildTree(post, in, r - 1 - (right - i), left, i - 1);
    root->right = buildTree(post, in, r - 1, i + 1, right);
    return root;
}

void levelOrder(BTNode * root){
    queue<BTNode *> q;
    q.push(root);
    bool space = false;
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        cout << (space? " ": "") << t->val;
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
        space = true;
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;
    vector<long long> post(ni), in(ni);
    for(long long i = 0; i < ni; ++i){
        cin >> post[i];
    }
    for(long long i = 0; i < ni; ++i){
        cin >> in[i];
    }
    levelOrder(buildTree(post, in, ni - 1, 0, ni - 1));

    return 0;
}
