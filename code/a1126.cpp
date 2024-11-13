#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>
using namespace std;

const long long MAX = 505;
vector<vector<long long>> graph(505);
vector<bool> visit(505);

void dfs(long long v){
    visit[v] = true;
    for(long long i: graph[v]){
        if(not visit[i]){
            dfs(i);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ni, mi;
    cin >> ni >> mi;
    while(mi--){
        long long ai, bi;
        cin >> ai >> bi;
        graph[ai].push_back(bi);
        graph[bi].push_back(ai);
    }
    dfs(1);
    long long vis = count(visit.begin() + 1, visit.begin() + ni + 1, false);
    long long num = count_if(graph.begin() + 1, graph.begin() + ni + 1, [](vector<long long> &a){return a.size() % 2 == 1;});
    for(long long i = 1; i <= ni; ++i){
        cout << graph[i].size() << (i == ni ? "\n": " ");
    }
    cout << (vis != 0 or(num != 0 and num != 2) ? "Non-Eulerian": num == 0 ? "Eulerian": "Semi-Eulerian");


    return 0;
}
