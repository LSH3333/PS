#include <iostream>
using namespace std;

int N;
int answer;
int board[110][110];

void DrawSquare(int _r, int _c) {
    for(int c = _c; c < _c+10; c++) {
        for(int r = _r; r < _r + 10; r++) {
            board[r][c] = 1;
        }
    }
}

void CalHeight() {
    for(int c = 0; c <= 100; c++) {
        for(int r = 1; r <= 100; r++) {
            if(board[r][c] == 0) continue;
            board[r][c] += board[r-1][c];
        }
    }
}

// (_r,_c)를 좌측하단으로 하는 직사각형
void CalArea(int _r, int _c) {
    int h = board[_r][_c];
    for(int c = _c; c <= 100; c++) {
        if(board[_r][c] == 0) return;
        h = min(h, board[_r][c]);
        int area = h * ((c+1) - _c);
        answer = max(answer, area);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        DrawSquare(100-b-10, a);
    }
    CalHeight();

    for(int r = 0; r <= 100; r++) {
        for (int c = 0; c <= 100; c++) {
            if(board[r][c] == 0) continue;
            CalArea(r, c);
        }
    }
    
    cout << answer;
}