#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

struct BTNode {
    string val;
    long long left, right;
};

vector<BTNode> tree(25);

void inOrder(long long root, long long r){
    if(root == -1)
        return;
    if(tree[root].left == -1 and tree[root].right == -1) {
        cout << tree[root].val;
        return;
    }
    if(root != r){
        cout << "(";
    }
    inOrder(tree[root].left, r);
    cout << tree[root].val;
    inOrder(tree[root].right, r);
    if(root != r){
        cout << ")";
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ni;
    cin >> ni;
    vector<bool> f(ni + 1);
    for(long long i = 1; i <= ni; ++i){
        cin >> tree[i].val >> tree[i].left >> tree[i].right;
        if(tree[i].left != -1){
            f[tree[i].left] = true;
        }
        if(tree[i].right != -1){
            f[tree[i].right] = true;
        }
    }
    long long root = find(f.begin() + 1, f.end(), false) - f.begin();
    inOrder(root, root);


    return 0;
}





