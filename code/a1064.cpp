#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

vector<long long > tree(1005), in(1005);
long long ni;
void inOrder(long long root, long long & p){
    if(root > ni)
        return;
    inOrder(root * 2, p);
    tree[root] = in[p++];
    inOrder(root * 2 + 1, p);
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> ni;
    for(long long i = 0; i < ni; ++i){
        cin >> in[i];
    }
    sort(in.begin(), in.begin() + ni);
    long long p = 0;
    inOrder(1, p);
    for(long long i = 1; i <= ni; ++i){
        cout << (i == 1 ? "": " ") << tree[i];
    }

    return 0;
}
