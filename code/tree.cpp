#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

// 完全二叉树 二叉查找树 并查集
// 从根节点到每个节点只有一条路径

struct TreeNode{
    long long val;
    vector<TreeNode *>child;
    TreeNode(long long v): val(v) {}
};

struct TreeNodeStatic{
    long long val;
    vector<long long> child;
    // TreeNodeStatic(long long v): val(v) {}
};

void preOrder(TreeNode * root){
    if(not root){
        return;
    }
    cout << root->val << " ";
    for(auto i: root->child){
        preOrder(i);
    }
}

void postOrder(TreeNode * root){
    if(not root){
        return;
    }
    for(auto i: root->child){
        postOrder(i);
    }
    cout << root->val << " ";
}

void levelOrder(TreeNode * root){
    queue<TreeNode *> q;
    q.push(root);
    while(not q.empty()){
        auto t = q.front();
        q.pop();
        cout << t->val << " ";
        for(auto i: t->child)
            q.push(i);
    }
}

void levelOrderLevelProcess(TreeNode * root){
    queue<TreeNode *> q;
    q.push(root);
    while(not q.empty()){
        long long s = q.size();
        while(s--){
            auto t = q.front();
            q.pop();
            cout << t->val << " ";
            for(auto i: t->child)
                q.push(i);
        }
    }
}

TreeNodeStatic tree[100];

void preOrderStatic(long long root){
    if(root == -1)
        return;
    cout << tree[root].val << " ";
    for(auto i: tree[root].child){
        preOrderStatic(i);
    }
}

void postOrderStatic(long long root){
    if(root == -1)
        return;
    for(auto i: tree[root].child)
        postOrderStatic(i);
    cout << tree[root].val << " ";
}

void levelOrderStatic(long long root){
    queue<long long> q;
    q.push(root);
    while(not q.empty()){
        long long s = q.size();
        while(s--){
            auto t = q.front();
            q.pop();
            cout << tree[t].val << (s == 0? "\n": " ");
            for(auto i: tree[t].child)
                q.push(i);
        }
    }
}






int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);




    return 0;
}


