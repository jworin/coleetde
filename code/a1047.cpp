#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long ni, ki;
    cin >> ni >> ki;
    vector<vector<long long>> course(ki + 1);
    vector<string> names;
    for(long long i = 0; i < ni; ++i) {
        string si;
        long long ci, ai;
        cin >> si >> ci;
        names.push_back(si);
        while(ci--) {
            cin >> ai;
            course[ai].push_back(i);
        }
    }

    // for(auto &s: names) {
    //     cout << s << endl;
    // }

    for(long long i = 1; i <= ki; ++i){
        cout << i << " " << course[i].size() << endl;
        sort(course[i].begin(), course[i].end(),
            [&names](long long a, long long b){
                return names[a] < names[b];
            });
        for(auto & s: course[i]) {
            cout << names[s] << "\n";
        }

    }



    return 0;
}
