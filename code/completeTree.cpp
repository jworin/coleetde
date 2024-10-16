#include <ios>
#include <queue>
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

bool isCompleteTree(BTNode * root){
    queue<pair<BTNode*, long long>> q;
    q.push({root, 1});
    for(long long i = 1; not q.empty(); ++i){
        auto t = q.front();
        q.pop();
        if(i != t.second)
            return false;
        if(t.first->left != nullptr)
            q.push({t.first->left, t.second*2});
        if(t.first->right != nullptr)
            q.push({t.first->right, t.second*2+1});
    }
    return true;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
