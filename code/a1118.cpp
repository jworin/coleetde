#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
#include <numeric>
#include <unordered_set>
using namespace std;

const long long MAXN = 1e4 + 5;
vector<long long> ufs(MAXN), num(MAXN);
void init(){iota(ufs.begin(), ufs.end(), 0);}

long long findRoot(long long x){return ufs[x] == x? x: ufs[x] = findRoot(ufs[x]);}

void unionSets(long long a, long long b){ufs[findRoot(a)] = findRoot(b);}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;

    init();

    unordered_set<long long> birds;

    for(long long index = 0; index < ni; ++index){
        long long temp;
        cin >> temp;
        long long prev = -1;
        for(long long j = 0; j < temp; ++j){
            long long t;
            cin >> t;
            birds.insert(t);
            if(prev == -1){
                prev = t;
            }else{
                unionSets(prev, t);
                prev = t;
            }
        }
    }



    long long cnt = 0;
    for(auto birds_index: birds){
        if(ufs[birds_index] == birds_index)
            cnt++;
    }
    cout << cnt << " " << birds.size() << endl;

    cin >> ni;
    for(long long i = 0; i < ni; ++i){
        long long a, b;
        cin >> a >> b;
        if(findRoot(a) == findRoot(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }



    return 0;
}
