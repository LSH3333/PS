#include <iostream>
using namespace std;

int N, M;
int board[55][55];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int GetNextDir(int dir) {
    if(dir == 0) return 3;
    else return dir-1;
}

void MoveRobot(int r, int c, int dir) {
    board[r][c] = 2;

    // 2. ?? ?? ?? 4? ? ???? ?? ? ?? ?? ??
    if(board[r-1][c] != 0 && board[r][c+1] != 0 && board[r+1][c] != 0 && board[r][c-1] != 0) {
        int oppositeDir = (dir + 2) % 4;
        int nr = r + dr[oppositeDir], nc = c + dc[oppositeDir];
        // ?? ?
        if(board[nr][nc] == 1) {
            return;
        }
            // ?? ??? ?? : ??
        else {
            MoveRobot(nr, nc, dir);
        }
    }
        // 3. ?? ?? ?? 4? ? ???? ?? ? ?? ?? ??
    else {
        int nextDir = GetNextDir(dir);
        int nr = r + dr[nextDir], nc = c + dc[nextDir];
        if(board[nr][nc] == 0) {
            MoveRobot(nr,nc,nextDir);
        }
        else {
            MoveRobot(r, c, nextDir);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int _r,_c,_dir;
    cin >> N >> M;
    cin >> _r >> _c >> _dir;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    MoveRobot(_r, _c, _dir);

    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == 2) cnt++;
        }
    }

    cout << cnt;

}
