#include <iostream>
#include <algorithm>
#include <pthread.h>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;




int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    vector<vector<long long>> graph(N + 1);
    vector<long long> indegrees(N + 1);
    vector<long long> ans;
    for(long long i = 0; i < M; ++i){
        long long a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegrees[b]++;
    }
    // for(long long i = 0; i < graph.size(); ++i){
    //     cout << i << ": " ;
    //     for(auto j: graph[i]){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    long long K;
    cin >> K;
    for(long long i = 0; i < K; ++i){
        vector<long long> temp(N + 1);
        vector<long long> tempDegrees = indegrees;
        bool flag = true;
        for(long long j = 0; j < N; ++j){
            cin >> temp[j];
            // cin >> temp[j];
            // cout << temp[j] << endl;
            // if(tempDegrees[temp[j]] != 0){
            //     flag = false;
            //     break;
            // }
            // for(auto it: graph[temp[j]]){
            //     tempDegrees[it]--;
            //     if(tempDegrees[it] < 0){
            //         flag = false;
            //         break;
            //     }
            // }
        }
        for(long long j = 0; j < N; ++j){
            if(tempDegrees[temp[j]] != 0 or tempDegrees[temp[j]] < 0){
                flag = false;
                break;
            }
            for(auto it: graph[temp[j]]){
                tempDegrees[it]--;
            }
        }
        if(flag){
            ans.push_back(i);
        }
    }

    for(long long i = 0; i < ans.size(); ++i){
        cout << (i == 0 ? "" : " ") << ans[i];
    }



    return 0;
}
