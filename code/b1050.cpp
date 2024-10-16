#include <functional>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 12
// 37 76 20 98 76 42 53 95 60 81 58 93
//98 95 93
//42 37 81
//53 20 76
//58 60 76


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    cin >> N;
    vector<long long> numbers(N);
    for(auto &i: numbers){
        cin >> i;
    }
    sort(numbers.begin(), numbers.end(), greater<long long>());
    long long n = -1, m = -1;
    for(n = (long long)sqrt(N); n > 0; n--) {
        if(N % n == 0){
            m = N / n;
            break;
        }
    }
    vector<vector<long long>> ans(m, vector<long long>(n));
    vector<array<long long, 2>>direc{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    long long d = 0, x = 0, y = 0;
    for(long long i = 0; i < N; ++i){
        ans[x][y] = numbers[i];
        long long nx = x + direc[d][0], ny = y + direc[d][1];
        if(nx >= 0 and nx < m and ny >= 0 and ny < n and ans[nx][ny] == 0){
            x = nx, y = ny;
        } else {
            d = (d + 1) % 4;
            x += direc[d][0], y += direc[d][1];
        }
    }
    for(auto & i: ans) {
        for(long long j = 0; j < i.size(); ++j) {
            cout << (j == 0 ? "": " ") << i[j];
        }
        cout << endl;
    }



    return 0;
}

