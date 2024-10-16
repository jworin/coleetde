#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long ni;
  cin >> ni;
  vector<long long> input(ni + 1);
  for (long long i = 1; i <= ni; ++i) {
    cin >> input[i];
  }
  for (long long i = 1; i <= ni; ++i) {
    for (long long j = i + 1; j <= ni; ++j) {
      long long lier = 0, wolflier = 0;
      for (long long k = 1; k <= ni; ++k) {
        if (input[k] > 0 xor (abs(input[k]) != i and abs(input[k]) != j)) {
          ++lier;
          if (k == i or k == j) {
            ++wolflier;
          }
        }
      }
      if (lier == 2 and wolflier == 1) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  cout << "No Solution" << endl;

  return 0;
}
