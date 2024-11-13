#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;
    vector<long long> v1(ni), v2(ni);
    for(long long & i: v1){
        cin >> i;
    }
    for(long long & i: v2){
        cin >> i;
    }
    vector<vector<long long>> inserts, merges;
    vector<long long> v = v1;
    for(long long i = 2; i <= ni; ++i){
        sort(v.begin(), v.begin() + i);
        inserts.push_back(v);
    }
    v = v1;
    for(long long i = 2; i <= ni; i *= 2){
        for(long long j = 0; j < ni; j += i){
            sort(v.begin() + j, v.begin() + min(j + i, ni));
        }
        merges.push_back(v);
    }
    for(long long i = 0; i < inserts.size(); ++i){
        if(inserts[i] == v2){
            cout << "Insertion Sort" << endl;
            for(long long j = 0; j < ni; ++j){
                cout << inserts[i + 1][j] << (j == ni - 1? "\n": " ");
            }
            break;
        }
    }
    for(long long i = 0; i < merges.size(); ++i){
        if(merges[i] == v2){
            cout << "Merge Sort" << endl;
            for(long long j = 0; j < ni; ++j){
                cout << merges[i + 1][j] << (j == ni - 1 ? "\n": " ");
            }
            break;
        }
    }

    return 0;
}
