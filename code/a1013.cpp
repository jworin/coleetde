#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;


const long long MAX = 1005;

vector<vector<long long>> graph(MAX);
vector<bool> visit(MAX);

void dfs(long long v){
    visit[v] = true;
    for(long long i: graph[v]){
        if(not visit[v]){
            dfs(v);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, mi, ki, ai, bi;
    cin >> ni >> mi >> ki;
    for(long long i = 0; i < mi; ++i){
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }
    while(ki--){
        cin >> ai;
        fill(visit.begin(), visit.begin() + ni + 1, false);
        visit[ai] = true;
        long long num = 0;
        for(long long i = 1; i <= ni; ++i){
            if(not visit[i]){
                ++num;
                dfs(i);
            }
        }
        cout << num - 1 << endl;
    }


    return 0;
}
