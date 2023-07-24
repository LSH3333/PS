#include <iostream>
using namespace std;

int N, M, answer;
int matrix[51][51];
int goal[51][51];

void Flip(int _r, int _c) {
    answer++;
    for(int r = _r; r < _r+3; r++) {
        for(int c = _c; c < _c+3; c++) {
            matrix[r][c] = (matrix[r][c] + 1) % 2;
        }
    }
}

bool CheckSame() {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if (matrix[r][c] != goal[r][c]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c; cin >> c;
            matrix[i][j] = int(c - '0');
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c; cin >> c;
            goal[i][j] = int(c - '0');
        }
    }


    for(int r = 0; r <= N-3; r++) {
        for (int c = 0; c <= M-3; c++) {
            if (matrix[r][c] != goal[r][c]) {
                Flip(r,c);
            }
        }
    }

    if(CheckSame()) {
        cout << answer;
    }
    else {
        cout << -1;
    }
}