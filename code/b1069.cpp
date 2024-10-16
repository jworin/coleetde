#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long mi, ni, si;
    cin >> mi >> ni >> si;
    vector<string> v(mi + 1);
    for(long long i = 1; i < v.size(); ++i)
        cin >> v[i];
    unordered_set<string> us;
    for(long long i = si; i < v.size(); i += ni) {
        while(i < v.size() and us.count(v[i]))
            ++i;
        if(i < v.size()){
            cout << v[i] << endl;
            us.insert(v[i]);
        }
    }


    if(us.empty())
        cout << "keep going..." << endl;

    return 0;
}




