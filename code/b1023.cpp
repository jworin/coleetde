#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<long long, 10> h{};
    for(long long i = 0; i < 10; ++i){
        cin >> h[i];
    }
    auto k = find_if(h.begin() + 1, h.end(), [](int a){return a > 0;}) - h.begin();
    cout << k;
    --h[k];
    for(long long i = 0; i < 10; ++i){
        while(h[i]--)
            cout << i;
    }

    return 0;
}
