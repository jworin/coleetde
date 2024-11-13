#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

void getPostFromBSTPre(vector<long long> &pre, long long left, long long right,
    vector<long long> &post, bool mirror){

    if(left > right)
        return;
    long long i = find_if(pre.begin() + left + 1, pre.begin() + right + 1,
        [&pre, left, mirror](long long a){
            return mirror? a < pre[left]: a >= pre[left];
        })
    - pre.begin();
    if(any_of(pre.begin() + i, pre.begin() + right + 1, [&pre, left, mirror](long long a){
        return mirror? a >= pre[left] : a < pre[left];
    })){
        return;
    }
    getPostFromBSTPre(pre, left + 1, i - 1, post, mirror);
    getPostFromBSTPre(pre, i, right, post, mirror);
    post.push_back(pre[left]);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;
    vector<long long> pre(ni), post1, post2;
    for(long long &i: pre){
        cin >> i;
    }
    getPostFromBSTPre(pre, 0, ni - 1, post1, true);
    getPostFromBSTPre(pre, 0, ni - 1, post2, false);
    if(post1.size() == ni or post2.size() == ni){
        cout << "YES" << endl;
        auto & post = post1.size() == ni ? post1: post2;
        for(long long i = 0; i < ni; ++i){
            cout << (i == 0 ? "": " ") << post[i];
        }
    }else {
        cout << "NO" << endl;
    }

    return 0;
}
