#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<long long> ans(54), order(54);
  long long times;
  cin >> times;
  for (long long i = 0; i < 54; ++i) {
    cin >> order[i];
  }
  iota(ans.begin(), ans.end(), 0); // 对容器的一个自增填充
  while (times--) {
    vector<long long> temp(54);
    for (long long i = 0; i < 54; ++i) {
      temp[order[i] - 1] = ans[i];
    }
    ans = temp;
  }
  string s = "SHCDJ";
  for (int i = 0; i < 54; ++i) {
    cout << (i > 0 ? " " : "") << s[ans[i] / 13] << ans[i] % 13 + 1;
  }

  return 0;
}
