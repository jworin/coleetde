
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}


long long binarySearch(vector<long long>& v, long long left, long long right, long long x) {
    while(left <= right){
        long long mid = (left + right) / 2;
        if(v[mid] == x)
            return mid;
        else if(v[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

long long lowerBound(vector<long long> & v, long long left, long long right, long long x) {
    while(left < right){
        long long mid = (left + right) / 2;
        if(v[mid] >= x)
            right = mid;
        else
            left = mid + 1;
    }
    return left > right or v[left] >= x ? -1: left;
}
