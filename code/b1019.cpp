#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[]) {

  string number4;
  cin >> number4;
  sort(number4.begin(), number4.end());

  if (number4.find_first_not_of(*number4.begin()) == string::npos) {
    cout << number4 + " - " + number4 + " = " + "0000";
  } else {
    string temp = number4;
    while (true) {


      while(temp.size() < 4)
        temp.push_back('0');

      sort(temp.begin(), temp.end());
      long long smallnumber = stoll(temp);
      // reverse(temp.begin(), temp.end());
      sort(temp.begin(), temp.end(), greater<char>());
      long long largenumber = stoll(temp);

      long long res = largenumber - smallnumber;
      temp = to_string(res);

      cout << setfill('0');
      cout << setw(4) << largenumber << " - " << setw(4) << smallnumber << " = "
           << setw(4) << res << '\n';

      if (res == 6174)
        break;
    }
  }

  return 0;
}
