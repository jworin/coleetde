#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string Plus(const string & a, const string & b){
    string ans;
    long long carry = 0;
    for(long long i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry != 0; --i, --j){
        long long p1 = i >= 0 ? a[i] - '0': 0, p2 = j >= 0 ? b[j] - '0': 0;
        long long k = p1 + p2 + carry;
        ans.push_back(k % 10 + '0');
        carry = k / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string Sub(string a, const string & b){
    string ans;
    for(long long i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j){
        long long p1 = i >= 0? a[i] - '0': 0, p2 = j >= 0 ? b[j] - '0': 0;
        if(p1 < p2){
            a[i - 1]--;
            p1 += 10;
        }
        long long k = p1 - p2;
        ans.push_back(k % 10 + '0');
    }
    while(ans.size() > 1 and ans.back() == '0'){
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string Multiply(const string & a, const string & b){
    long long m = a.size(), n = b.size();
    string ans(n+m, '0');
    for(long long i = m - 1; i >= 0; --i){
        for(long long j = n - 1; j >= 0; --j){
            long long k = (a[i] - '0') * (b[j] - '0');
            long long t = k + (ans[i + j + 1] - '0');
            ans[i + j] += t / 10;
            ans[i + j + 1] = t % 10 + '0';
        }
    }
    ans.erase(0, ans.find_first_not_of('0'));
    return ans.empty() ? "0": ans;
}

pair<string, long long> Divmod(const string & a, long long b){
    string ans;
    long long mod = 0;
    for(char c: a){
        mod = c - '0' + mod * 10;
        ans.push_back(mod/b + '0');
        mod %= b;
    }
    ans.erase(0, ans.find_first_not_of('0'));
    return {ans.empty()? "0": ans, mod};
}




int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a;

    for(long long i = 0; i < 10; ++i){
        if(equal(a.begin(), a.end(), a.rbegin())){
            cout << a << " is a palindromic number." << endl;
            return 0;
        }
        b = a;
        reverse(b.begin(), b.end());
        string c = Plus(a, b);
        cout << a << " + " << b << " = " << c << endl;
        a = c;
    }
    cout << "Not found in 10 iterations." << endl;

    return 0;
}
