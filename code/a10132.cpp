#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

const long long MAX = 1005;
vector<long long> ufs(MAX);
void init() { iota(ufs.begin(), ufs.end(), 0); }
long long findRoot(long long x) {
  return ufs[x] == x ? x : ufs[x] = findRoot(ufs[x]);
}
void unionSets(long long a, long long b) { ufs[findRoot(a)] = findRoot(b); }

int main(int argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long ni, mi, ki, ai;
  cin >> ni >> mi >> ki;

  vector<array<long long, 2>> edges(mi);
  for (auto &e : edges) {
    cin >> e[0] >> e[1];
  }
  while (ki--) {
    cin >> ai;
    init();
    for (auto &e : edges) {
      if (e[0] != ai and e[1] != ai) {
        unionSets(e[0], e[1]);
      }
    }
    long long num = 0;
    for (long long i = 1; i <= ni; ++i) {
      if (i != ai and i == ufs[i]) {
        ++num;
      }
    }
    cout << num - 1 << endl;
  }

  return 0;
}
