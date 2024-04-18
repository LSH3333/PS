#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string history;
char board[100][100];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void Init() {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            board[i][j] = '#';
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    Init();
    cin >> N;
    cin >> history;

    int dir = 2;
    int r = 50, c = 50;
    board[r][c] = '.';
    for (auto x: history) {
        if (x == 'R') {
            dir = (dir + 1) % 4;
        }
        else if (x == 'L') {
            dir = dir - 1;
            if(dir == -1) dir = 3;
        }
        else {
            r = r + dr[dir];
            c = c + dc[dir];
            board[r][c] = '.';
        }
    }

    int sr=200,sc=200,er=-1,ec=-1;
    // ? ??
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if (board[i][j] == '.') {
                sr = min(sr, i);
                sc = min(sc, j);
                er = max(er, i);
                ec = max(ec, j);
            }
        }
    }

    // ??
    for(int i = sr; i <= er; i++) {
        for(int j = sc; j <= ec; j++) {
            cout << board[i][j];
        } cout << '\n';
    }
}