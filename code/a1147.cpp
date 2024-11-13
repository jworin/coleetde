#include <functional>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <iomanip>

#include <queue>

using namespace std;

long long mi, ni;

void PostOrder(vector<long long> &v, long long root, long long &num){
    if(root >= v.size())
        return;
    PostOrder(v, root * 2 + 1, num);
    PostOrder(v, root * 2 + 2, num);
    cout << v[root] << (num++ < ni - 1? " ": "\n");
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> mi >> ni;
    vector<long long> v(ni);
    while(mi--){
        for(long long &i: v){
            cin >> i;
        }
        if(is_heap(v.begin(), v.end())){
            cout << "Max Heap" << endl;
        }else if(is_heap(v.begin(), v.end(), greater<long long>())){
            cout << "Min Heap" << endl;
        }else{
            cout << "Not Heap" << endl;
        }
        long long num = 0;
        PostOrder(v, 0, num);
    }

    return 0;
}
