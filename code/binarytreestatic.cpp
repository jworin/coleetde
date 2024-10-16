#include <endian.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

struct BTNode {
    long long val, left, right;
    // BTNode(long long v, long long left = -1, long long right = -1): val(v), left(left), right(right) {}
};

BTNode tree[100];


void preOrder(long long root){
    if(root == -1)
        return;
    cout << tree[root].val << " ";
    preOrder(tree[root].left);
    preOrder(tree[root].right);
}

void inOrder(long long root){
    if(root == -1)
        return;
    inOrder(tree[root].left);
    cout << tree[root].val << " ";
    inOrder(tree[root].right);
}

void postOrder(long long root){
    if(root == -1)
        return;
    postOrder(tree[root].left);
    postOrder(tree[root].right);
    cout << tree[root].val << " ";
}

void levelOrder(long long root){
    queue<long long> q;
    q.push(root);
    while(not q.empty()){
        long long s = q.size();
        while(s--){
            auto t = q.front();
            q.pop();
            cout << tree[t].val << " ";
            if(tree[t].left != -1)
                q.push(tree[t].left);
            if(tree[t].right != -1)
                q.push(tree[t].right);
        }
    }
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
