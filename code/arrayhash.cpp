#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct arrayHash{
    long long operator() (const array<long long, 2> & p) const {return p[0] * 1e9 + p[1];}
};


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<array<long long, 2>, long long, arrayHash> um;
    unordered_set<array<long long, 2>, arrayHash> us;


    return 0;
}
