#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;

vector<vector<long long>> graph(MAX);

struct Edge{
    long long to;
    long long cost;
    // Edge(long long t, long long c): to(t), cost(c){}
};

vector<vector<Edge>> graph2(Max);

vector<bool> visit(MAX);

void dfs(long long v){
    visit[v] = true;
    cout << v << " ";
    for(long long i: graph[v]){
        if(not visit[i]){
            dfs(i);
        }
    }
}

void bfs(int v){
    vector<bool>inQueue(n);
    queue<long long> q;
    q.push(v);
    inQueue[v] = true;
    while(not q.empty()){
        v = q.front();
        q.pop();
        cout << v << " ";
        for(long long i: graph[v]){
            if(not inQueue[i]){
                q.push(i);
                inQueue[i] = true;
            }
        }
    }

}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    graph[2].push_back(Edge(3, 6));


    return 0;
}
