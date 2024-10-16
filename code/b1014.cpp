#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setfill('0');
    unordered_map<char, string> week = {
        {'A', "MON"},
        {'B', "TUE"},
        {'C', "WED"},
        {'D', "THU"},
        {'E', "FRI"},
        {'F', "SAT"},
        {'G', "SUN"},
    };
    unordered_map<char, long long> hour;
    for(long long i = 0; i < 24; ++i){
        hour.insert({i < 10 ? i + '0' : i - 10 + 'A', i});
    }
    string s1, s2;
    cin >> s1 >> s2;
    for(long long i = 0, c = 0; i < min(s1.size(), s2.size()); ++i){
        if(s1[i] == s2[i] and c == 0 and week.count(s1[i])){
            cout << week[s1[i]] << " ";
            ++c;
        } else if(s1[i] == s2[i] and c == 1 and hour.count(s1[i])) {
            cout << setw(2) << hour[s1[i]] << ":";
            ++c;
        }
    }
    cin >> s1 >> s2;
    for(long long i = 0, c = 0; i < min(s1.size(), s2.size()); ++i){
        if(s1[i] == s2[i] and isalpha(s1[i])) {
            cout << setw(2) << i;
            break;
        }
    }

    return 0;
}
