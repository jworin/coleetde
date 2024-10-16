#include <algorithm>
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;

class Testee{
public:
    string id;
    long long score;
    array<long, 2> rank;
    long long location;
    long long local_rank;
    long long global_rank;
    Testee(string i, long long s, long long n): id(i), score(s), location(n) {}
};


int main(int argc, const char * argv[]) {

    long long locationN;
    cin >> locationN;
    vector<Testee> total_testee;
    for(long long i = 0; i < locationN; i++) {
        long long testeeK;
        cin >> testeeK;
        vector<Testee> local_testee;
        for(long long j = 0; j < testeeK; j++) {
            string temp_id;
            long long temp_score;
            cin >> temp_id >> temp_score;
            Testee local_temp(temp_id, temp_score, i + 1);
            local_testee.push_back(local_temp);
        }

        sort(local_testee.begin(), local_testee.end(),
            [](const Testee & t1, const Testee & t2){
                return tie(t2.score, t1.id) < tie(t1.score, t2.id);
        });

        long long local_rank = 1;
        for(long long k = 0; k < local_testee.size(); ++k){
            if(k == 0){
                local_testee[k].local_rank = local_rank;
            } else {
                if (local_testee[k].score == local_testee[k - 1].score) {
                    local_testee[k].local_rank = local_testee[k - 1].local_rank;
                }
                else {
                    local_testee[k].local_rank = local_rank;
                }
            }
            local_rank += 1;
            // total_testee.push_back(local_testee[i]);
        }
        total_testee.insert(total_testee.end(), local_testee.begin(), local_testee.end());
    }


    // for(long long index = 0; index < total_testee.size(); index++){
    //     cout << total_testee[index].id << " " << total_testee[index].score << endl;
    // }

    sort(total_testee.begin(), total_testee.end(),
        [](const Testee& t1, const Testee& t2){
            return tie(t2.score, t1.id) < tie(t1.score, t2.id);
        });


    // for(long long index = 0; index < total_testee.size(); index++){
    //     cout << total_testee[index].id << " " << total_testee[index].score << endl;
    // }

    cout << total_testee.size() << endl;
    long long total_rank = 1;
    for(long long i = 0; i < total_testee.size(); ++i) {
        cout << total_testee[i].id << " ";
        if(i == 0) {
            total_testee[i].global_rank = total_rank;
        } else {
            if(total_testee[i].score == total_testee[i - 1].score)
                total_testee[i].global_rank = total_testee[i - 1].global_rank;
            else
                total_testee[i].global_rank = total_rank;
        }
        total_rank += 1;
        cout << total_testee[i].global_rank << " " << total_testee[i].location << " "
        << total_testee[i].local_rank << endl;
    }




    return 0;
}
