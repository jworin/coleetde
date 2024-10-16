#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

class Student {
public:
    long long id, de, cai, total, level;
    Student(long long i, long long d, long long c, long long le): id(i), de(d), cai(c), level(le) {
        total = de + cai;
    }
};


int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, L, H;
    cin >> N >> L >> H;

    vector<Student> students;

    cout << setfill('0');

    while(N--){
        long long id, de, cai, level;
        cin >> id >> de >> cai;
        if(de < L or cai < L)
            continue;
        if(de >= H and cai >= H) {
            level = 1;
        } else if(de >= H and cai < H) {
            level = 2;
        } else if(de < H and cai < H and de >= cai) {
            level = 3;
        } else {
            level = 4;
        }
        students.push_back(Student(id, de, cai, level));
    }
    sort(students.begin(), students.end(),
        [](const Student &s1, const Student &s2){
            return tie(s1.level, s2.total, s2.de, s1.id) < tie(s2.level, s1.total, s1.de, s2.id);
        });

    cout << students.size() << endl;

    for(auto &stu: students) {
        cout << setw(8) << stu.id << " " << stu.de << " " << stu.cai << endl;
    }

    return 0;
}



