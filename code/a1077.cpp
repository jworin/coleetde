#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
// #include<limits>
#include<climits>

using namespace std;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, m = INT_MAX;
    cin >> ni;
    cin.get();
    vector<string> v(ni);

    string ans;
    for(auto & i: v) {
        getline(cin, i); // 这里可以直接存储string里面的word
        reverse(i.begin(), i.end());
        m = min(m, static_cast<long long>(i.size()));
    }
    for(long long i = 0; i < m; ++i) {
        for(auto & j: v) {
            if(j[i] != v[0][i]) {
                goto loop;
            }
        }
        ans.push_back(v[0][i]);
    }

loop:
    reverse(ans.begin(), ans.end());
    cout << (ans.empty() ? "nai" : ans) << endl;


    return 0;
}
