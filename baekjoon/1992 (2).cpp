#include <iostream>
using namespace std;

int N;
char arr[70][70];

bool IsItAllSame(const string &str) {
    char tok = str[0];
    for(const auto &x : str) {
        if(x != tok) return false;
    }
    return true;
}

string DivideAndConquer(int len, int _r, int _c) {
    if(len == 1) {
        string ret;
        ret += arr[_r][_c];
        return ret;
    }

    string str;
    str += DivideAndConquer(len / 2, _r, _c);
    str += DivideAndConquer(len / 2, _r, _c + len / 2);
    str += DivideAndConquer(len/2, _r+len/2, _c);
    str += DivideAndConquer(len / 2, _r + len / 2, _c + len / 2);

    string ret;
    if(IsItAllSame(str)) {
        ret.push_back(str[0]);
    }
    else {
        ret.push_back('(');
        ret += str;
        ret.push_back(')');
    }

    return ret;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char c; cin >> c;
            arr[i][j] = c;
        }
    }

    cout << DivideAndConquer(N, 0, 0);
}