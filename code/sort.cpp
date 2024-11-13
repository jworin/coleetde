#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <queue>

using namespace std;

void InsertSort(vector<long long> &v){
    for(long long i = 0; i < v.size(); ++i){
        long long t = v[i], j;
        for(j = i; j >= 1 and v[j - 1] > t; --j){
            v[j] = v[j - 1];
        }
        v[j] = t;
    }
}

void ShellSort(vector<long long> &v){
    for(long long inc = v.size() / 2; inc >= 1; inc /= 2){
        for(long long i = inc; i < v.size(); ++i){
            long long t = v[i], j;
            for(j = i; j >= inc and v[j - inc] > t; j -= inc){
                v[j] = v[j - inc];
            }
            v[j] = t;
        }
    }
}

void SelectSort(vector<long long> &v){
    for(long long i = 0; i < v.size(); ++i){
        long long k = i;
        for(long long j = i + 1; j < v.size(); ++j){
            if(v[j] < v[k]){
                k = j;
            }
        }
        long long t = v[k];
        v[k] = v[i];
        v[i] = t;
    }
}

void BubbleSort(vector<long long> &v){
    for(long long i = 0; i < v.size(); ++i){
        bool flag = true;
        for(long long j = 1; j < v.size() - i; ++j){
            if(v[j] < v[j - 1]){
                flag = false;
                long long t = v[j];
                v[j] = v[j - 1];
                v[j - 1] = t;
            }
        }
        if(flag){
            break;
        }
    }
}


void QSort(vector<long long> &v, long long left, long long right){
    if(left >= right)
        return;
    long long pivot = v[left], i = left, j = right;
    while(i < j){
        while(i < j and v[j] >= pivot){
            --j;
        }
        if(i < j){
            v[i++] = v[j];
        }
        while(i < j and v[i] <= pivot){
            ++i;
        }
        if(i < j){
            v[j--] = v[i];
        }
    }
    v[i] = pivot;
    QSort(v, left, i - 1);
    QSort(v, i + 1, right);
}

void QuickSort(vector<long long> &v) {
    QSort(v, 0, v.size() - 1 );
}


void Merge(vector<long long> &v, vector<long long> &a, long long left, long long mid, long long right){
    for(long long i = left, j = mid + 1, k = left; k <= right; ++k){
        if(i > mid){
            a[k] = v[j++];
        }else if(j > right){
            a[k] = v[i++];
        }else if(v[i] < v[j]){
            a[k] = v[i++];
        }else {
            a[k] = v[j++];
        }
    }
    for(long long i = left; i <= right; ++i){
        v[i] = a[i];
    }
}

void MSort(vector<long long> & v, vector<long long> &a, long long left, long long right){
    if(left >= right){
        return;
    }
    long long mid = (left + right) / 2;
    MSort(v, a, left, mid);
    MSort(v, a, mid + 1, right);
    Merge(v, a, left, mid, right);
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
