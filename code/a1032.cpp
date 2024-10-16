#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<string, long long>> input((long long)(1e6));
    long long start1, start2, ni;
    cin >> start1 >> start2 >> ni;
    for(long long i = 0; i < ni; ++i){
        long long address, nextA;
        string data;
        cin >> address >> data >> nextA;
        input[address] = {data, nextA};
    }

    unordered_set<long long> us;
    while(start1 != -1){
        us.insert(start1);
        start1 = input[start1].second;
    }
    bool flag = false;
    while(start2 != -1){
        if(us.count(start2)) {
            cout << setfill('0') << setw(5) << start2 << endl;
            flag = true;
            break;
        }
        start2 = input[start2].second;
    }

    if(!flag){
        cout << "-1" << endl;
    }


    return 0;
}
