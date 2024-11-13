#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;

// 下表从0开始的树，左子节点 2k + 1, 2k + 2
// 下调是针对所有非叶子节点进行的

void Down(vector<long long> &v, long long n, long long p){ // 在取出
    long long t = v[p];
    while(2 * p + 1 < n){
        long long child = 2 * p + 1;
        if(child + 1 < n and v[child] < v[child + 1]){
            child++;
        }
        if(t < v[child]){
            v[p] = v[child];
            p = child;
        }else{
            break;
        }
    }
    v[p] = t;

}

void HeapSort(vector<long long> &v){
    for(long long i = v.size() / 2; i >= 0; --i){
        Down(v, v.size(), i);
    }
    for(long long i = v.size() - 1; i > 0; --i){
        long long t = v[i];
        v[i] = v[0];
        v[0] = t;
        Down(v, i, 0);
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}


