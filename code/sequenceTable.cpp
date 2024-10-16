#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

// vector array string
// long long A[MAX];
// long long len;

void insertElement(long long A[], long long & len, long long p, long long x){
    for(auto i = len; i > p; --i){
        A[i] = A[i - 1];
    }
    A[p] = x;
    ++len;
}

void deleteElement(long long A[], long long & len, long long p){
    for(auto i = p; i < len; ++i) {
        A[i] = A[i + 1];
    }
    --len;
}

void traversal(long long A[], long long len){
    for(long long i = 0; i < len; ++i) {
        cout << A[i] << " ";
    }
}

long long findElement(long long A[], long long len, long long v){
    for(long long i = 0; i < len; ++i){
        if(A[i] == v)
            return i;
    }
    return -1;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long MAX = 100;
    long long A[MAX];
    long long len = 0;
    for(long long i = 1; i <= 5; ++i){
        insertElement(A, len, i - 1, i);
    }




    return 0;
}
