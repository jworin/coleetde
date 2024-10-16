#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
using namespace std;

using F = array<long long, 2>;

F input() {
    F f;
    char c;
    cin >> f[0] >> c >> f[1];
    return f;
}

long long gcd(long long a, long long b){ return b == 0? a: gcd(b, a % b);}

void simplify(F &f){
    if(f[0] == 0){
        f[1] = 1;
        return;
    }
    if(f[1] < 0){
        f[1] = -f[1];
        f[0] = -f[0];
    }
    long long d = gcd(abs(f[0]), abs(f[1]));

    f[0] /= d;
    f[1] /= d;
}

F Plus(const F& f1, const F& f2) {
    F f;
    f[0] = f1[0] * f2[1] + f2[0] * f1[1];
    f[1] = f1[1] * f2[1];
    simplify(f);
    return f;
}

F Sub(const F & f1, const F & f2){
    F f;
    f[0] = f1[0] * f2[1] - f2[0] * f1[1];
    f[1] = f1[1] * f2[1];
    simplify(f);
    return f;
}

F Multiply(const F & f1, const F & f2){
    F f;
    f[0] = f1[0] * f2[0];
    f[1] = f1[1] * f2[1];
    simplify(f);
    return f;
}

F Div(const F & f1, const F & f2){
    F f;
    f[0] = f1[0] * f2[1];
    f[1] = f1[1] * f2[0];
    simplify(f);
    return f;
}

void output(const F & f){
    if(f[0] < 0)
        cout << '(';
    if(f[1] == 1){
        cout << f[0];
    }else if(abs(f[0]) < f[1]){
        cout << f[0] << "/" << f[1];
    } else {
        cout << f[0] / f[1] << " " << abs(f[0]) % f[1] << "/" << f[1];
    }

    if(f[0] < 0)
        cout << ')';

}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto f1 = input(), f2 = input();
    simplify(f1);
    simplify(f2);

    unordered_map<char, function<F(F, F)>> um = {
        {'+', Plus},
        {'-', Sub},
        {'*', Multiply},
        {'/', Div},
    };
    for(char c : {'+', '-', '*', '/'}) {
        output(f1);
        cout << ' ' << c << ' ';
        output(f2);
        cout << " = ";
        if(c == '/' and f2[0] == 0){
            cout << "Inf\n";
        }else {
            auto f3 = um[c](f1, f2);
            output(f3);
            cout << '\n';
        }
    }

    return 0;
}
