#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define EMP 9

int mark[3][3];
int original[3][3];


bool Check() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(original[i][j] != mark[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool IsGameOver() {
    for(int i = 0; i < 3; i++) {
        if(mark[i][0] != EMP && mark[i][0] == mark[i][1] && mark[i][1] == mark[i][2]) return true;
        if(mark[0][i] != EMP && mark[0][i] == mark[1][i] && mark[1][i] == mark[2][i]) return true;
    }
    if(mark[0][0] != EMP && mark[0][0] == mark[1][1] && mark[1][1] == mark[2][2]) return true;
    if(mark[0][2] != EMP && mark[0][2] == mark[1][1] && mark[1][1] == mark[2][0]) return true;
    return false;
}

void dfs(int idx, int turn, bool &found) {
    if (Check()) {
        found = true;
        return;
    }

    if(IsGameOver()) {
        return;
    }

    if(idx == 9 || found) {
        return;
    }

    for(int i = 0; i < 9; i++) {
        int r = i / 3;
        int c = i % 3;
        if(mark[r][c] != EMP) continue;
        mark[r][c] = turn;
        dfs(idx + 1, (turn + 1) % 2, found);
        mark[r][c] = EMP;
    }
}

int solution(vector<string> board) {
    int answer = -1;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            mark[i][j] = EMP;

            int n;
            if(board[i][j] == 'O') n = 0;
            else if(board[i][j] == 'X') n = 1;
            else n = EMP;
            original[i][j] = n;
        }
    }


    bool found = false;
    dfs(0, 0, found);

    if(found) answer = 1;
    else answer = 0;

    return answer;
}

int main() {
    vector<string> board =
            {"OOX",
             "XXO",
             "OXO"};
    cout << solution(board);
}