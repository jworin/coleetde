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

void insertElement(BTNode * & root, long long x){
    if(not root){
        root = new BTNode();
        root->val = x;
    }else if(x <= root->val){
        insertElement(root->left, x);
    }else{
        insertElement(root->right, x);
    }


}

BTNode * findElement(BTNode * root, long long x){
    if(not root or root->val == x){
        return root;
    }else if(x <= root->val){
        return findElement(root->left, x);
    }else{
        return findElement(root->right, x);
    }
}

// 时间复杂度都是O(h)

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BTNode * head = nullptr;
    for(int i = 0; i < 5; ++i){
        insertElement(head, i);
    }


    return 0;
}
