#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class Student {
public:
    string id, name;
    long long grade;
};


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ni, ci;
    cin >> ni >> ci;
    vector<Student> v(ni);
    for(long long i = 0; i < ni; ++i) {
        cin >> v[i].id >> v[i].name >> v[i].grade;
    }
    vector<function<bool(const Student &, const Student &)>> f = {
        [](const Student & s1, const Student & s2) { return s1.id < s2.id;},
        [](const Student & s1, const Student & s2) { return tie(s1.name, s1.id) < tie(s2.name, s2.id);},
        [](const Student & s1, const Student & s2) { return tie(s1.grade, s1.id) < tie(s2.grade, s2.id);}
    };

    sort(v.begin(), v.end(), f[ci - 1]);
    for(auto &i: v) {
        cout << i.id << " " << i.name << " " << i.grade << endl;
    }


    return 0;
}
