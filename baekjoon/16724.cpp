#include <iostream>
using namespace std;


int N, M;
int board[1010][1010];
int visited[1010][1010];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer;

void dfs(int _r, int _c, int num) {
    // 현재 루프에서 방문한곳을 다시 되돌아왔을 경우
    if(visited[_r][_c] == num) {
        answer++;
        return;
    }
    // 방문한적 있는데 & 현재 루프에서 방문한 곳이 아닌 경우
    if(visited[_r][_c] != 0 && visited[_r][_c] != num) {
        return;
    }

    visited[_r][_c] = num;

    int dir = board[_r][_c];
    int nr = _r + dr[dir];
    int nc = _c + dc[dir];

    dfs(nr,nc, num);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char c; cin >> c;
            if(c == 'U') board[i][j] = 0;
            else if(c == 'R') board[i][j] = 1;
            else if(c == 'D') board[i][j] = 2;
            else board[i][j] = 3;
        }
    }

    int num = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(visited[i][j] != 0) continue;
            dfs(i, j, num);
            num++;
        }
    }

    cout << answer;

}