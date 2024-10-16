
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

vector<long long> decToR(long long n, long long R) {
    vector<long long> ans;
    do {
        ans.push_back(n % R);
        n /= R;
    } while (n != 0);
    reverse(ans.begin(), ans.end());
    return ans;
}


long long rToDec(const vector<long long> & r, long long R) {
    long long d = 0;
    for(long long i: r) {
        d = d * R + i;
    }
    return d;
}

