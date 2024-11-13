#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;

const long long MAX = 1005;
long long ni, mi, ki;
vector<vector<long long>> graph(MAX);
vector<long long> top(MAX), degree(MAX);
bool isTopSort() {
    vector<long long> temp(degree.begin(), degree.begin() + ni + 1);
    for(long long i = 0; i < ni; ++i){
        if(temp[top[i]] != 0){
            return false;
        }
        for(long long j: graph[top[i]]){
            --temp[j];
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(mi--){
        long long ai, bi;
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        ++degree[bi];
    }
    cin >> ki;
    vector<long long> ans;
    for(long long i = 0; i < ki; ++i){
        for(long long j = 0; j < ni; ++j){
            cin >> top[j];
        }
        if(not isTopSort()){
            ans.push_back(i);
        }
    }
    for(long long i = 0; i < ans.size(); ++i){
        cout << ans[i] << (i == ans.size() - 1? "\n": " ");
    }

    return 0;
}
