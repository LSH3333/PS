#include <iostream>
#include <vector>
using namespace std;

int R, C, N;
int board[201][201];

void TimePass() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == -2) continue;
            board[i][j]--;
        }
    }
}

void BombEmptyArea() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == -2) {
                board[i][j] = 3;
            }
        }
    }
}

void Explode() {
    vector<pair<int,int>> targets;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == 0) {
                targets.push_back({i, j});
            }
        }
    }

    for(auto x : targets) {
        int r = x.first, c = x.second;
        board[r][c] = -2;
        if(r-1 >= 0) board[r-1][c] = -2;
        if(c+1 < C) board[r][c+1] = -2;
        if(r+1 < R) board[r+1][c] = -2;
        if(c-1 >= 0) board[r][c-1] = -2;
    }
}

void Print() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(board[i][j] == -2) cout << '.';
            else cout << 'O';
//            cout << board[i][j] << ' ';
        } cout << '\n';
    } cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> N;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            char c; cin >> c;
            if (c == '.') {
                board[i][j] = -2;
            } else {
                board[i][j] = 3;
            }
        }
    }

    TimePass(); // 0? ?

    TimePass(); // 1? ?
    if(N == 1) {
        Print(); return 0;
    }

    BombEmptyArea(); // ? ?? ?? ?? ??
    TimePass(); // 2??

    for(int sec = 3; sec <= N; sec++) {
        if(sec % 2 != 0) {
            Explode();
        } else {
            BombEmptyArea();
        }
        TimePass();
//        Print();
    }

    Print();
}