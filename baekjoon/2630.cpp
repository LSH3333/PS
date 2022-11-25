#include <iostream>
using namespace std;

int oneCnt, zeroCnt;
char board[130][130];

void Cal(int n, int _r, int _c) {
    char tmp = board[_r][_c];
    bool trigger = true;
    for(int r = _r; r < _r + n; r++) {
        for(int c = _c; c < _c + n; c++) {
            if(board[r][c] != tmp) {
                trigger = false;
                break;
            }
        }
    }

    if(trigger) {
        if(tmp == '0') zeroCnt++;
        else oneCnt++;
    }
    else {
        Cal(n / 2, _r, _c);
        Cal(n / 2, _r + n / 2, _c);
        Cal(n / 2, _r, _c + n / 2);
        Cal(n / 2, _r + n / 2, _c + n / 2);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    Cal(N, 0, 0);

    cout << zeroCnt << '\n' << oneCnt;
}