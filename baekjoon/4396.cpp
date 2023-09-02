#include <iostream>
using namespace std;

int N;
char bombBoard[11][11];
char openedBoard[11][11];
char answerBoard[11][11];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool bombOpened;

void Open(int r, int c) {
    if (bombBoard[r][c] == '*') {
        bombOpened = true;
        return;
    }

    int bombCnt = 0;
    for(int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr >= 0 && nr < N && nc >= 0 && nc < N) {
            if(bombBoard[nr][nc] == '*') {
                bombCnt++;
            }
        }
    }

    answerBoard[r][c] = char(bombCnt + '0');
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> bombBoard[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> openedBoard[i][j];
        }
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (openedBoard[i][j] == 'x') {
                Open(i, j);
            } else {
                answerBoard[i][j] = '.';
            }
        }
    }

    if(bombOpened) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (bombBoard[i][j] == '*') {
                    answerBoard[i][j] = '*';
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << answerBoard[i][j];
        } cout << '\n';
    }
}