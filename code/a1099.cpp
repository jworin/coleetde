#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

class BTNode {
public:
    long long val;
    long long left = -1, right = -1;
};



void inOrderTrav(vector<BTNode> &arrayTree, vector<long long> &numb, long long  root, long long &index){
    // if(arrayTree[root].left == -1 && arrayTree[root].right == -1){
        // return;
    // }
    if(root == -1)
        return;
    inOrderTrav(arrayTree, numb, arrayTree[root].left, index);
    arrayTree[root].val = numb[index++];
    // cout << index << " ";
    // index++;
    inOrderTrav(arrayTree, numb, arrayTree[root].right, index);
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long ni;
    cin >> ni;
    vector<BTNode> arrayTree(ni + 10);
    vector<long long> numb(ni);

    for(long long i = 0; i < ni; ++i){
        cin >> arrayTree[i].left >> arrayTree[i].right;
    }
    for(long long i = 0; i < ni; ++i){
        cin >> numb[i];
    }
    sort(numb.begin(), numb.end());

    // for(long long i = 0; i < ni; ++i){
        // cout << numb[i] << " ";
    // }


    long long start_index = 0;
    inOrderTrav(arrayTree, numb, 0, start_index);

    queue<long long> q;
    q.push(0);
    long long cnt = 0;
    while(!q.empty()){
        long long temp = q.front();
        q.pop();
        cout << ((cnt++) == 0? "": " ") << arrayTree[temp].val;
        if(arrayTree[temp].left != -1)
            q.push(arrayTree[temp].left);
        if(arrayTree[temp].right != -1)
            q.push(arrayTree[temp].right);
    }
    cout << endl;


    return 0;
}
