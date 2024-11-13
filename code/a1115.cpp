#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

class BTNode {
public:
    long long val = -10001;
    BTNode *left=nullptr, *right=nullptr;
};


void insertElement(BTNode *&root, long long x){  // 这边一定要用一个引用，不然传递参数的时候进去的只是
    if(!root){
        root = new BTNode;
        root->val = x;
        return;
    }
    if(x <= root->val){
        insertElement(root->left, x);
    }else{
        insertElement(root->right, x);
    }
}

// void levelOrder(BTNode *root, vector<long long>levelNodeCoutns){
//     queue<BTNode *> q;
//     q.push(root);
//     while(!q.empty()){

//     }
// }



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BTNode *root = nullptr;
    long long n;
    cin >> n;
    for(long long i = 0; i < n; ++i){
        long long temp;
        cin >> temp;
        insertElement(root, temp);
    }

    vector<long long>levelNodeCounts;

    queue<BTNode *> q;
    q.push(root);
    while(!q.empty()){
        long long s = q.size();
        levelNodeCounts.push_back(s);
        while(s--){
            auto temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

    // if(levelNodeCounts.size() >= 2){
    //     long long n1 = *levelNodeCounts.back();
    //     long long n2 = *(levelNodeCounts.back() - 1);
    // }

    // 二叉查找树的中根遍历顺序一定是升序


    long long n1index = levelNodeCounts.size() - 1;
    long long n2index = levelNodeCounts.size() - 2;
    long long n1 = 0, n2 = 0;
    if(n1index >= 0){
        n1 = levelNodeCounts[n1index];
    }
    if(n2index >= 0){
        n2 = levelNodeCounts[n2index];
    }

    cout << n1 << " + " << n2 << " = " << n1 + n2;



    return 0;
}
