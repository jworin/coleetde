#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long n){
    if(n < 2)
        return false;
    long long target = (long long)sqrt(n);
    for(long long i = 2; i <= target; ++i){
        if(n % i == 0)
            return false;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, ans = 0;
    cin >> ni;
    for(long long i = 5; i <= ni; i += 2){
        if(isPrime(i) && isPrime(i - 2)){
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}





