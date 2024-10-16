#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    cin >> ni;
    long long cur = 0, ans = 0;
    while(ni--){
        long long target;
        cin >> target;
        if(target > cur){
            ans += (target - cur) * 6;
        } else if(target < cur) {
            ans += (cur - target) * 4;
        }
        cur = target;
        ans += 5;
    }
    cout << ans << endl;

    return 0;
}
