#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}

bool sequenceSearchDivideConquer(const vector<long long> &v, long long left, long long right, long long x){
    if(left > right)
        return false;
    if(left == right)
        return v[left] == x;
    long long mid = (left + right) / 2;
    return sequenceSearchDivideConquer(v, left, mid, x) or sequenceSearchDivideConquer(v, mid + 1, right, x);

}

