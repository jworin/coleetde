#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long mi, ni, ki;
    cin >> mi >> ni >> ki;

    vector<long long> seq(ni);
    while(ki--) {
        for (long long i = 0; i < ni; ++i) {
            cin >> seq[i];
        }
        long long cur = 1;
        stack<long long> st;
        for(long long i : seq) {
            while(cur <= ni and st.size() < mi and (st.empty() or st.top() < i)) {
                st.push(cur++);
            }
            if(st.empty() or st.top() != i) {
                cout << "NO" << endl;
                goto loop;
            }
            st.pop();
        }
        cout << "YES" << endl;
    loop:;
    }

    return 0;
}


