#include <iostream>
using namespace std;

int N, M;
char board[51][51];
int answer = 100000;

void Check(int _r, int _c, char initial) {
    int cnt = 0;
    for(int r = _r; r < _r + 8; r++) {
        char target = initial;
        for(int c = _c; c < _c + 8; c++) {
            if(board[r][c] != target) {
                cnt++;
            }
            target = target == 'W' ? 'B' : 'W';
        }
        initial = initial == 'W' ? 'B' : 'W';
    }
    answer = min(answer, cnt);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0 ; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int r = 0; r <= N-8; r++) {
        for(int c = 0; c <= M-8; c++) {
            Check(r, c, 'W');
            Check(r, c, 'B');
        }
    }

    cout << answer;
}