#include <cstdlib>
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
    for(long long i = 2; i <= target; ++i)
        if(n % i == 0)
            return false;
    return true;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long length, window_size;
    long long ans = 0;
    cin >> length >> window_size;
    string input_string;
    cin >> input_string;
    bool flag = false;
    for(auto i = input_string.begin(); i < input_string.end() - window_size + 1; ++i){
        string sub_str = input_string.substr(i - input_string.begin(), window_size);
        long long num_res = stoll(sub_str);
        if(isPrime(num_res)){
            cout << sub_str << endl;
            flag = true;
            break;
        }
    }
    if(not flag)
        cout << "404" << endl;

    // long long li, ki;
    // string s;
    // cin >> li >> ki >> s;

    // for(int i = 0; i < s.size() - ki + 1; ++i){
    //     string n = s.substr(i, ki);
    //     if(isPrime(stoll(n))){
    //         cout << n;
    //         return 0;
    //     }
    // }
    // cout << "404";

    // return 0;
}




