#include <iostream>
using namespace std;

int N, answer;
bool board[100][100];

void Fill(int _r, int _c) {
    for(int r = _r; r < _r + 10; r++) {
        for(int c = _c; c < _c + 10; c++) {
            board[r][c] = true;
        }
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int r, c; cin >> r >> c;
        Fill(r,c);
    }

    for(int r = 0; r < 100; r++) {
        for(int c = 0; c < 100; c++) {
            answer += board[r][c];
        }
    }

    cout << answer;
}