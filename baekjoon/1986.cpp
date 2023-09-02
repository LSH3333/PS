#include <iostream>
#include <vector>
using namespace std;

#define DANGER 1

int N, M;
char board[1010][1010];
int answer[1010][1010];

int knight_dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int knight_dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
void Knight(int r, int c) {
    for(int i = 0; i < 8; i++) {
        int nr = r + knight_dr[i], nc = c + knight_dc[i];
        if(nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
        answer[nr][nc] = DANGER;
    }
}

int queen_dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int queen_dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
void Queen(int r, int c, int dr, int dc) {
    answer[r][c] = DANGER;
    int nr = r + dr, nc = c + dc;
    if(nr > 0 && nr <= N && nc > 0 && nc <= M) {
        if (board[nr][nc] == '0') {
            Queen(nr, nc, dr, dc);
        }
    }
}

void Init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            board[i][j] = '0';
        }
    }
}

void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << answer[i][j] << ' ';
        } cout << endl;
    }
}

int main() {
    int Q, K, P;
    cin >> N >> M;
    Init();
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int r,c; cin >> r >> c;
        board[r][c] = 'Q';
    }
    cin >> K;
    for(int i = 0; i < K; i++) {
        int r,c; cin >> r >> c;
        board[r][c] = 'K';
    }
    cin >> P;
    for(int i = 0; i < P; i++) {
        int r,c; cin >> r >> c;
        board[r][c] = 'P';
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if (board[i][j] == 'K') {
                answer[i][j] = DANGER;
                Knight(i, j);
            }
            else if(board[i][j] == 'Q') {
                answer[i][j] = DANGER;
                for(int dir = 0; dir < 8; dir++) {
                    Queen(i, j, queen_dr[dir], queen_dc[dir]);
                }
            }
            else if(board[i][j] == 'P'){
                answer[i][j] = DANGER;
            }
        }
    }


    int safeCnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(answer[i][j] != DANGER) {
                safeCnt++;
            }
        }
    }
    cout << safeCnt;
}