#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;
vector<long long> path;

void dfs(vector<long long> &v, long long root){
    if(root >= v.size()){
        return;
    }
    if(root * 2 + 1 >= v.size()){
        for(long long i: path){
            cout << i << " ";
        }
        cout << v[root] << endl;
        return;
    }
    path.push_back(v[root]);
    dfs(v, root * 2 + 2);
    dfs(v, root * 2 + 1);
    path.pop_back();
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;
    vector<long long> v(ni);
    for(long long &i: v){
        cin >> i;
    }
    dfs(v, 0);
    if(is_heap(v.begin(), v.end())){
        cout << "Max Heap" << endl;
    }else if(is_heap(v.begin(), v.end(), greater<long long>())){
        cout << "Min Heap" << endl;
    }else{
        cout << "Not Heap" << endl;
    }


    return 0;
}
