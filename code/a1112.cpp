#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ki;

    string si;
    cin >> ki >> si;

    array<long long, 128> h{};

    for(long long i = 0; i < si.size();){
        if(h[si[i]] != -1){
            long long j = si.find_first_not_of(si[i], i + 1);
            if(j == -1){
                j = si.size();
            }
            h[si[i]] = (j - i) % ki != 0 ? -1: 1;
            i = j;
        } else {
            ++i;
        }
    }

    string ans;  // 字符串也能pushback
    for(long long i = 0; i < si.size();){
        ans.push_back(si[i]);
        if(h[si[i]] == -1){
            ++i;
            continue;
        }
        if(h[si[i]] == 1){
            cout << si[i];
            h[si[i]] = 2;
        }
        i += ki;
    }
    cout << '\n' << ans;

    return 0;
}
