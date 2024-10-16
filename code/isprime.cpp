#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
using namespace std;

bool isPrime(long long n) {
    if(n < 2) {
        return false;
    }
    for(long long i = 2; i < n; ++i) {
        if(n % i == 0)
            return false;
    }
    return true;
}

bool isPrime2(long long n) {
    if(n < 2) {
        return false;
    }
    for(long long i = 2; i <= (long long)sqrt(n); ++i){
        if(n % i == 0)
            return false;
    }
    return true;
}

vector<long long> prime;

void getPrime(long long n = (long long)1e5 + 5){
    vector<bool> f(n);
    for(long long i = 2; i <= n; ++i){
        if(not f[i]){
            prime.push_back(i);
            for(long long j = i + i; j < n; j = j + i){
                f[j] = true;
            }
        }
    }
}


// unordered_map<long long, long long> factor;
map<long long, long long> factor;
void getFactor(long long n){
    getPrime();
    for(long long i: prime){
        while(n % i == 0){
            ++factor[i];
            n /= i;
        }
        if(n == 1)
            break;
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;
    if(ni == 1) {
        cout << "1=1" << endl;
        return 0;
    }
    getFactor(ni);
    cout << ni << "=";
    for(auto i = factor.begin(); i != factor.end(); ++i){
        cout << (i == factor.begin() ? "": "*") << i ->first;
        if(i -> second > 1){
            cout << "^" << i ->second;
        }
    }


    return 0;
}





