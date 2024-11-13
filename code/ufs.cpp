#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
#include <numeric>

using namespace std;

vector<long long> ufs;

void init() {
    iota(ufs.begin(), ufs.end(), 0);
}

long long findRoot(long long x){
    if(ufs[x] == x){
        return x;
    }
    long long r = findRoot(x);
    ufs[x] = r;
    return r;
}

void unionSet(long long a, long long b){
    long long ra = findRoot(a), rb = findRoot(b);
    if(ra != rb)
        ufs[ra] = rb;
}


vector<long long> ufs(MAX);
void init() {iota(ufs.begin(), ufs.end(), 0);}
long long findRoot(long long x){ return ufs[x] == x? x: ufs[x] = findRoot(x);}
void unionSets(long long a, long long b) {ufs[findRoot(a)] = findRoot(b);}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
