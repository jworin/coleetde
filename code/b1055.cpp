#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    using Person = pair<string, long long>;
    long long ni, ki;
    cin >> ni >> ki;

    vector<Person> p(ni);
    for(long long i = 0; i < ni; ++i){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(),
        [](const Person & p1, const Person & p2){
            return tie(p2.second, p1.first) < tie(p1.second, p2.first);
        });
    for(long long i = 0; i < ni;){
        long long left = i, right = i + ni / ki + (i == 0 ? ni % ki: 0);
        vector<long long> ans(right - left);
        long long mid = ans.size() / 2;
        for(long long j = left; j < right; ++j){
            long long k = j - left;
            if(k % 2 == 1) {
                ans[mid - (k + 1) / 2] = j;
            } else {
                ans[mid + k / 2] = j;
            }
        }
        i = right;
        for(long long j = 0; j < ans.size(); ++j) {
            cout << (j == 0 ? "": " ") << p[ans[j]].first;
        }
        cout << endl;
    }


    return 0;
}
