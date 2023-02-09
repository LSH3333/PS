#include <iostream>
#include <vector>
using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int N, answer = 10000;
char board[55][55];
bool visited[55][55][4];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int sr, sc, er, ec;

// direction: 빛이 향하는 방향
// return: 거울에 의해 갈 수 있는 방향 두 가지
vector<int> mirrorDirection(int direction) {
    if(direction == UP || direction == DOWN) {
        return {LEFT, RIGHT};
    }
    else {
        return {UP, DOWN};
    }
}

void dfs(int r, int c, int direction, int depth, int mirrorNum) {
    // 다른 문 도착
    if (depth != 0 && r == er && c == ec) {
        answer = min(answer, mirrorNum);
        return;
    }
    if(mirrorNum >= answer) return;

    // 문에서 출발
    if(depth == 0) {
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(board[nr][nc] == '*' || visited[nr][nc][i]) continue;
            visited[nr][nc][i] = true;
            dfs(nr, nc, i , depth + 1, mirrorNum);
            visited[nr][nc][i] = false;
        }
    }
    // 이외
    else {
        if (board[r][c] == '.') {
            int nr = r + dr[direction], nc = c + dc[direction];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N && board[nr][nc] != '*' && !visited[nr][nc][direction]) {
                visited[nr][nc][direction] = true;
                dfs(nr, nc, direction, depth + 1, mirrorNum);
                visited[nr][nc][direction] = false;
            }
        }
        else if (board[r][c] == '!') {
            vector<int> nextDir = mirrorDirection(direction);
            nextDir.push_back(direction); // 원래 방향 즉 거울 설치 안함
            for (auto next: nextDir) {
                int nr = r + dr[next], nc = c + dc[next];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                if(board[nr][nc] == '*' || visited[nr][nc][next]) continue;
                visited[nr][nc][next] = true;
                if(next == direction) dfs(nr, nc, next, depth + 1, mirrorNum);
                else dfs(nr, nc, next, depth + 1, mirrorNum+1);
                visited[nr][nc][next] = false;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // 시작 문 위치
    cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == '#' && cnt == 0) {
                sr = i; sc = j; cnt++;
            }
            else if(board[i][j] == '#' && cnt == 1) {
                er = i; ec = j;
            }
        }
    }

    dfs(sr, sc, 0, 0, 0);

    cout << answer;
}