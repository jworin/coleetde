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

    vector<array<long long, 2>> input((long long)1e6, {-1, -1});
    long long start, ni, ki;
    cin >> start >> ni >> ki;
    for(long long i = 0; i < ni; ++i){
        long long address, data, nextA;
        cin >> address >> data >> nextA;
        input[address] = {data, nextA};  // array类型可以直接用大括号初始化
    }
    vector<long long> lst;
    while(start != -1){
        lst.push_back(start);
        start = input[start][1];
    }

    for(long long i = ki; i <= lst.size(); i += ki){
        reverse(lst.begin() + i - ki, lst.begin() + i);
    }

    cout << setfill('0');
    for(long long i = 0; i < lst.size() - 1; ++i){
        cout << setw(5) << lst[i] << " " << input[lst[i]][0] << " " << setw(5) << lst[i + 1] << endl;
    }
    cout << setw(5) << lst.back() << " " << input[lst.back()][0] << " " << "-1" << endl;


    return 0;
}




