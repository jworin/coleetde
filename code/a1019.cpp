#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<long long> decToR(long long n, long long R) {
    vector<long long> ans;
    do {
        ans.push_back(n % R);
        n /= R;
    }while(n != 0);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, bi;
    cin >> ni >> bi;
    auto v = decToR(ni, bi);
    cout << (equal(v.begin(), v.end(), v.rbegin()) ? "Yes": "No") << endl;
    for(int i = 0; i < v.size(); ++i) {
        cout << (i == 0 ? "": " ") << v[i];
    }


    return 0;
}
