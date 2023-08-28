#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, M;
char board[10][10];
int answer = -1;

void IsItComplete(const string &res) {
    int number = stoi(res);
    int sq = (int)sqrt(number);
    if (sq * sq == number) {
        answer = max(answer, number);
    }
}

string Cal(int r, int c, int dr, int dc) {
    string res;
    res.push_back(board[r][c]);
    IsItComplete(res);
    if(dr == 0 && dc == 0) {
        return res;
    }

    while (r + dr >= 1 && r + dr <= 9 && c + dc >= 1 && c + dc <= 9) {
        res.push_back(board[r+dr][c+dc]);
        IsItComplete(res);
        r = r + dr;
        c = c + dc;
    }

    return res;
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {

            for(int dr = -N; dr < N; dr++) {
                for(int dc = -M; dc < M; dc++) {
                    string res = Cal(r, c, dr, dc);
                }
            }
        }
    }

    cout << answer;
}