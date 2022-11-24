#include <iostream>
using namespace std;

int N;
char board[70][70];

string Cal(int _r, int _c, int n) {
    bool trigger = true;
    char tmp = board[_r][_c];
    for(int r = _r; r < _r + n; r++) {
        for(int c = _c; c < _c + n; c++) {
            if(board[r][c] != tmp) {
                trigger = false;
                break;
            }
        }
    }

    // 모두 같음
    if(trigger) {
        string ret;
        ret.push_back(tmp);
        return ret;
    }
    else {
        string ret;
        ret += Cal(_r, _c, n / 2);
        ret += Cal(_r, _c + n / 2, n / 2);
        ret += Cal(_r + n / 2, _c, n / 2);
        ret += Cal(_r + n / 2, _c + n / 2, n / 2);
        return "(" + ret + ")";
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    string ans = Cal(0, 0, N);

    cout << ans;
}