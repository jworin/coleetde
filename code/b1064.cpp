#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    set<long long> ans;
    for(long long i = 0; i < n; ++i){
        long long temp;
        cin >> temp;
        long long accumula = 0;
        do{
            long long target = temp % 10;
            accumula += target;
            temp /= 10;
        }while(temp != 0);
        ans.insert(accumula);
    }

    cout << ans.size() << endl;
    for(auto i = ans.begin(); i != ans.end(); ++i){
        cout << (i == ans.begin() ? "" : " ") << *i;
    }


    return 0;
}
