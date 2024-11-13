#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
#include <climits>
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
    vector<vector<long long>> inserts, heaps;
    vector<long long> v = v1;
    for(long long i = 2; i <= ni; ++i){
        sort(v.begin(), v.begin() + i);
        inserts.push_back(v);
    }
    v = v1;
    make_heap(v.begin(), v.end());
    for(long long i = 0; i < ni; ++i){
        pop_heap(v.begin(), v.begin() + ni - i);
        heaps.push_back(v);
    }
    for(long long i = 0; i < inserts.size(); ++i){
        if(inserts[i] == v2){
            cout << "Insertion Sort" << endl;
            for(long long j = 0; j < ni; ++j){
                cout << inserts[i + 1][j] << (j == ni - 1 ? "\n": " ");
            }
            break;
        }
    }
    for(long long i = 0; i < heaps.size(); ++i){
        if(heaps[i] == v2){
            cout << "Heap Sort" << endl;
            for(long long j = 0; j < ni; ++j){
                cout << heaps[i + 1][j] << (j == ni - 1 ? "\n": " ");
            }
            break;
        }
    }

    return 0;
}
