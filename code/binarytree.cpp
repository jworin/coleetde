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
    BTNode *left, *right;
    BTNode(long long v, BTNode *l=nullptr, BTNode *r=nullptr): val(v), left(l), right(r) {}
};

void preOrder(BTNode * root){
    if(not root)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BTNode * root){
    if(not root)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(BTNode * root){
    if(not root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void levelOrder(BTNode * root){
    queue<BTNode *> q;
    q.push(root);
    while(!q.empty()){
        long long s = q.size();
        while(s--){
            auto t = q.front();
            q.pop();
            cout << t->val << (s==0? "\n": ' ');
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
            // q.push(t->left);
            // q.push(t->right);
        }
    }
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
