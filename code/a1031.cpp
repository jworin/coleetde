#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    long long n1 = (str.size() + 2) / 3;
    long long n2 = str.size() + 2 - 2 * n1;
    for (int i = 0; i < n1 - 1; i++) {
        cout << str[i];
        for(int j = 0; j < n2 - 2; j++) {
            cout << " ";
        }
        cout << str[str.size() - i - 1] << "\n";
    }
    cout << str.substr(n1 - 1, n2);


    return 0;
}
