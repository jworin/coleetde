#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<long long> decToR(long long n, long long R) {
    vector<long long> ans;
    do{
        ans.push_back(n % R);
        n /= R;
   }while(n != 0);
   reverse(ans.begin(), ans.end());
   return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ai, bi, di;
    cin >> ai >> bi >> di;
    ai += bi;

    for(auto i: decToR(ai, di)){
        cout << i;
    }


    return 0;
}
