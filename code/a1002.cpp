#include <functional>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<long long, double, greater<long long>> um;

    long long ki, ai;
    double bi;
    cin >> ki;
    while(ki--) {
        cin >> ai >> bi;
        um[ai] += bi;
    }
    cin >> ki;
    while(ki--) {
        cin >> ai >> bi;
        um[ai] += bi;
        if(um[ai] == 0) {
            um.erase(ai);
        }
    }
    if(um.empty()) {
        cout << "0" << endl;
    }
    else {
        cout << fixed << setprecision(1);
        cout << um.size();
        for(auto & i:um) {
            cout << " " << i.first << " " << i.second;
        }
        cout << endl;
    }


    return 0;
}
