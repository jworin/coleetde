#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

struct BTNode {
    long long val;
    BTNode *left, *right;
};

BTNode *buildTreePre(vector<long long> &pre, vector<long long> &in, long long r, long long left, long long right){
    if(left > right){
        return nullptr;
    }
    long long i = find(in.begin(), in.end(), pre[r]) - in.begin();
    auto root = new BTNode();
    root->val = pre[r];
    root->left = buildTreePre(pre, in, r + 1, left, i - 1);
    root->right = buildTreePre(pre, in, r + 1 + i - left, i + 1, right);
}

void getPostFromPreIn(vector<long long> &pre, vector<long long> &in, long long r, long long left, long long right){
    if(left > right){
        return;
    }
    long long i = find(in.begin(), in.end(), pre[r]) - in.begin();
    getPostFromPreIn(pre, in, r + 1, left, i - 1);
    getPostFromPreIn(pre, in, r + 1 + i - left, i + 1, right);
    cout << pre[r] << " ";
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);




    return 0;
}



