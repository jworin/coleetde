#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;

vector<vector<long long>> graph(MAX);
vector<long long> top(MAX), degree(MAX);

bool topSort(){
    queue<long long> q;
    for(long long i = 0; i < ni; ++i){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        long long p = q.front();
        q.pop();
        top.push_back(p);
        for(auto i: graph[p]){
            if(--degree[i] == 0){
                q.push(i);
            }
        }
    }
    return top.size() == ni?

}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
