#include <iostream>
using namespace std;

int N;
char board[6][6];
int minAns = 10000000, maxAns = -10000000;

int Cal(const string &ops) {
    int res = int(ops.front()-'0');
    for(int i = 0; i < ops.size(); i+=2) {
        if(ops[i+1] == '+') {
            res += int(ops[i+2]-'0');
        } else if (ops[i + 1] == '-') {
            res -= int(ops[i+2]-'0');
        } else if (ops[i + 1] == '*') {
            res *= int(ops[i+2]-'0');
        }
    }
    return res;
}

void dfs(int r, int c, string &ops) {
    ops.push_back(board[r][c]);
    // ??
    if(r == N-1 && c == N-1) {
        int res = Cal(ops);
        minAns = min(minAns, res);
        maxAns = max(maxAns, res);
        return;
    }

    // go right
    if(c+1 < N) {
        dfs(r, c+1, ops);
        ops.pop_back();
    }
    // go down
    if(r+1 < N) {
        dfs(r+1, c, ops);
        ops.pop_back();
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    string ops;
    dfs(0, 0, ops);

    cout << maxAns << ' ' << minAns;
}