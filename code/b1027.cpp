#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    char ci;
    cin >> ni >> ci;

    long long k = (long long)sqrt((ni + 1) / 2 * 1.0);
    long long row = 2 * k - 1;

    vector<vector<char>> ans(row, vector<char>(row, ' '));
    for(long long i = 0; i < k; ++i) {
        for(long long j = k - 1 - i; j < k + i; ++j) {
            ans[k - 1 - i][j] = ans[k - 1 + i][j] = ci;
        }
    }

    for(long long i = 0; i < row; ++i) {
        bool output = true;
        for(long long j = 0; j < row; ++j) {
            if( ans[i][j] == ' ' and !output)
                break;
            if(ans[i][j] != ' ') {
                output = false;
            }
            cout << ans[i][j];
        }
        cout << endl;
    }

    cout << ni - 2 * k * k + 1;
    return 0;
}



