#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[6][6];
bool visited[6][6];
int answer;

void Print() {
    cout << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << visited[i][j] << ' ';
        } cout << endl;
    }
}

void dfs(int loc, int total) {
    if (loc == N * M) {
        answer = max(answer, total);
        return;
    }
    int r = loc / M;
    int c = loc % M;


    if (c+1 < M && r+1 < N &&
        !visited[r][c] && !visited[r][c + 1] && !visited[r + 1][c]) {
        visited[r][c] = true;
        visited[r][c+1] = true;
        visited[r+1][c] = true;
        dfs(loc + 1, total + (board[r][c] * 2) + board[r][c + 1] + board[r + 1][c]);
        visited[r][c] = false;
        visited[r][c+1] = false;
        visited[r+1][c] = false;
    }
    if (c - 1 >= 0 && r + 1 < N && !visited[r][c] && !visited[r][c - 1] && !visited[r + 1][c]) {
        visited[r][c] = true;
        visited[r][c-1] = true;
        visited[r+1][c] = true;
        dfs(loc + 1, total + (board[r][c] * 2) + board[r][c - 1] + board[r + 1][c]);
        visited[r][c] = false;
        visited[r][c-1] = false;
        visited[r+1][c] = false;
    }
    if (r - 1 >= 0 && c + 1 < M && !visited[r][c] && !visited[r - 1][c] && !visited[r][c + 1]) {
        visited[r][c] = true;
        visited[r-1][c] = true;
        visited[r][c+1] = true;
        dfs(loc + 1, total + (board[r][c] * 2) + board[r - 1][c] + board[r][c + 1]);
        visited[r][c] = false;
        visited[r-1][c] = false;
        visited[r][c+1] = false;
    }
    if (r - 1 >= 0 && c - 1 >= 0 && !visited[r][c] && !visited[r - 1][c] && !visited[r][c - 1]) {
        visited[r][c] = true;
        visited[r-1][c] = true;
        visited[r][c-1] = true;
        dfs(loc + 1, total + (board[r][c] * 2) + board[r - 1][c] + board[r][c - 1]);
        visited[r][c] = false;
        visited[r-1][c] = false;
        visited[r][c-1] = false;
    }

    dfs(loc+1, total);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0);

    cout << answer;
}