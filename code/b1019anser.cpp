#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << setfill('0');

  long long ni;
  cin >> ni;
  do{
    string temp = to_string(ni);
    while(temp.size() < 4){
      temp.push_back('0');
    }
    sort(temp.begin(), temp.end());
    long long a = stoll(temp);
    // sort(temp.begin(), temp.end(), greater<char>());
    reverse(temp.begin(), temp.end());
    long long b = stoll(temp);
    ni = b - a;
    cout << setw(4) << b << " - " << setw(4) << a << " = " << setw(4) << ni << endl;

  }while(ni != 0 && ni != 6174);

  return 0;
}
