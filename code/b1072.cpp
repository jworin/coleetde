#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long ni, mi, ki, ai;
    cin >> ni >> mi;

    vector<long long> v(mi);
    for(long long i = 0; i < mi; ++i) {
        cin >> v[i];
    }
    array<long long, 2> ans{};
    string name;
    long long stu_cnt = 0, item_cnt = 0;
    while(ni--) {
        cin >> name >> ki;
        bool output = false;
        vector<long long>illegal_item;
        while(ki--) {
            cin >> ai;
            if(any_of(v.begin(), v.end(),[&ai](long long a){return a == ai;})) {
                output = true;
                illegal_item.push_back(ai);
                item_cnt += 1;
            }
        }
        if(output) {
            stu_cnt += 1;
            cout << name << ":";
            for(auto &j: illegal_item) {
                cout << setfill('0') << " " << setw(4) << j;
            }
            cout << endl;
        }
    }
    cout << stu_cnt << " " << item_cnt << endl;




    return 0;
}
