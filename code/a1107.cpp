#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
#include <numeric>

using namespace std;

const long long MAXN = 1e3 + 5;
vector<long long> ufs(MAXN), num(MAXN);
void init(){iota(ufs.begin(), ufs.end(), 0);}
long long findRoot(long long x){return ufs[x] == x? x: ufs[x] = findRoot(ufs[x]);}
void unionSets(long long a, long long b){ufs[findRoot(a)] = findRoot(b);}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ni, ki, ai;
    char c;
    cin >> ni;
    unordered_map<long long, long long> hobby;
    init();
    for(long long i = 1; i <= ni; ++i){
        cin >> ki >> c;
        while(ki--){
            cin >> ai;
            if(hobby.count(ai)){
                unionSets(hobby[ai], i);
            }else{
                hobby[ai] = i;
            }
        }
    }
    for(long long i = 1; i <= ni; ++i){
        num[findRoot(i)]++;
    }
    sort(num.begin(), num.begin() + ni + 2, greater<long long>());
    long long n = find(num.begin(), num.begin() + ni + 2, 0) - num.begin();
    cout << n << endl;
    for(long long i = 0; i < n; ++i){
        cout << (i == 0 ? "": " ") << num[i];
    }



    return 0;
}
