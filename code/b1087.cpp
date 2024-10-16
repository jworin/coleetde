#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni;
    unordered_set<long long> us;
    for(long long i = 1; i <= ni; ++i) {
        us.insert(i / 2 + i / 3 + i / 5);
    }
    cout << us.size() << endl;


    return 0;
}
