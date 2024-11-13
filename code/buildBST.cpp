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
    BTNode(long long v, BTNode *l = nullptr, BTNode *r = nullptr): val(v) {};
};

BTNode * buildBST(vector<long long> &pre, long long left, long long right){
    if(left > right){
        return nullptr;
    }
    long long i = find_if(pre.begin() + left, pre.begin() + right + 1,
        [&pre, left](long long a)
        {return a > pre[left];}
    ) - pre.begin();
    auto root = new BTNode(pre[left]);
    root->left = buildBST(pre, left + 1, i - 1);
    root->right = buildBST(pre, i, right);
    return root;
}


void getPostFromBSTPre(vector<long long> &pre, long long left, long long right){
    if(left > right){
        return;
    }
    long long i = find_if(pre.begin() + left, pre.begin() + right + 1,
        [&pre, left](long long a)
        {return a > pre[left];}
    ) - pre.begin();
    auto root = new BTNode(pre[left]);
    getPostFromBSTPre(pre, left + 1, i - 1);
    getPostFromBSTPre(pre, i, right);
    cout << pre[left] << " ";
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
