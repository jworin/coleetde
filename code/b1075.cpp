#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<array<long long, 2>> input((long long)(1e6), {-1, -1});
    long long start, ni, ki;
    cin >> start >> ni >> ki;
    for(long long i = 0; i < ni; ++i){
        long long address, data, nextA;
        cin >> address >> data >> nextA;
        input[address] = {data, nextA};
    }
    vector<vector<long long>> lst(3);
    while(start != -1){
        long long flag = input[start][0] < 0 ? 0: input[start][0] > ki ? 2 : 1;
        lst[flag].push_back(start);
        start = input[start][1];
    }
    lst[0].insert(lst[0].end(), lst[1].begin(), lst[1].end());
    lst[0].insert(lst[0].end(), lst[2].begin(), lst[2].end());

    cout << setfill('0');
    for(long long i = 0; i < lst[0].size() - 1; ++i){
        cout << setw(5) << lst[0][i] << " " << input[lst[0][i]][0] << " " << setw(5) << lst[0][i + 1] << endl;
    }
    cout << setw(5) << lst[0].back() << " " << input[lst[0].back()][0] << " " << "-1" << endl;



    return 0;
}



