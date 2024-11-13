#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

void getPostFromPreIn(vector<long long> &pre, vector<long long> & in, long long r, long long left, long long right){
    if(left > right)
        return;
    long long i = find(in.begin(), in.end(), pre[r]) - in.begin();
    getPostFromPreIn(pre, in, r+1, left, i-1);
    getPostFromPreIn(pre, in, r + 1 + i - left, i + 1, right);
    cout << pre[r] << (r == 0? "": " ");
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, ai;
    cin >> ni;
    string si;

    stack<long long> st;

    vector<long long>pre, in;
    for(long long i = 0; i < 2 * ni; ++i){
        cin >> si;
        if(si == "Push"){
            cin >> ai;
            st.push(ai);
            pre.push_back(ai);
        }else{
            in.push_back(st.top());
            st.pop();
        }
    }

    getPostFromPreIn(pre, in, 0, 0, in.size() - 1);

    return 0;
}
