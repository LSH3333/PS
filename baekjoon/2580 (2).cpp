#include <iostream>
using namespace std;

int board[9][9];

void Print() {
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            cout << board[r][c] << ' ';
        } cout << '\n';
    }
}

// [r][c] ? n ?? ??
bool Check(int n, int r, int c) {
    // ??? ???
    for(int i = 0; i < 9; i++) {
        if(board[i][c] == n || board[r][i] == n) return false;
    }
    // ???
    int _r = (r / 3) * 3;
    int _c = (c / 3) * 3;


    for(int i = _r; i < _r + 3; i++) {
        for(int j = _c; j < _c + 3; j++) {
            if(board[i][j] == n) {
                return false;
            }
        }
    }

    return true;
}

void BackTracking(int idx) {
    if(idx == 81) {
        Print();
        exit(0);
    }

    int r = idx / 9, c = idx % 9;

    if(board[r][c] != 0) {
        BackTracking(idx+1);
    }
    else {
        for(int n = 1; n <= 9; n++) {
            if(Check(n, r, c)) {
                board[r][c] = n;
                BackTracking(idx+1);
                board[r][c] = 0;
            }
        }
    }
}

int main() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    BackTracking(0);



}