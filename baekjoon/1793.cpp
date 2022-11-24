#include <iostream>
#include <algorithm>
using namespace std;

int N;
string d[300][4];

string Add(const string &_a, const string &_b) {
    // 자리수 통일
    string a, b;
    if(_a.size() > _b.size()) {
        a = _a; b = _b;
    }
    else {
        a = _b; b = _a;
    }
    string tmp;
    for(int i = 0; i < a.size()-b.size(); i++) {
        tmp.push_back('0');
    }
    b = tmp + b;

    // 계산
    string ret;
    int add = 0;
    for(int i = (int)a.size()-1; i >= 0; i--) {
        int n1 = a[i]-'0';
        int n2 = b[i]-'0';
        int res = n1 + n2 + add;
        if(res > 9) {
            add = 1;
            ret.push_back(char((res % 10) + '0'));
        }
        else {
            add = 0;
            ret.push_back(char(res+'0'));
        }
    }
    if(add == 1) ret.push_back('1');
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    d[0][3] = "1";
    d[1][0] = "1"; d[1][1] = "0"; d[1][2] = "0"; d[1][3] = "1";
    d[2][0] = "1"; d[2][1] = "1"; d[2][2] = "1"; d[2][3] = "3";

    for(int i = 3; i <= 250; i++) {
        d[i][0] = d[i-1][3];
        d[i][1] = d[i-2][3];
        d[i][2] = d[i-2][3];
        d[i][3] = Add(Add(d[i][0], d[i][1]), d[i][2]);
    }

    while(true) {
        cin >> N;
        if(cin.eof()) break;
        cout << d[N][3] << '\n';
    }
}