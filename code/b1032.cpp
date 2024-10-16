#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
using namespace std;



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // array<long long, (long long)(1e5 + 5)> h{};
    // long long n;
    // cin >> n;
    // while(n--){
    //     long long a, b;
    //     cin >> a >> b;
    //     h[a] += b;
    // }
    // auto i = max_element(h.begin(), h.end());
    // cout << (i - h.begin()) << " " << *i;

    long long n;
    cin >> n;
    map<long long, long long> m;
    long long max_i = -1, max = -1;
    for(long long i = 0; i < n; ++i){
        long long a, b;
        cin >> a >> b;
        if(m.find(a) == m.end()){
            m[a] = 0;
        }
        m[a] += b;
        if(m[a] > max){
            max = m[a];
            max_i = a;
        }

    }
    cout << max_i << " " << max << endl;





    return 0;
}
