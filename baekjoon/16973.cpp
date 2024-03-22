#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 10000000
int N, M, H, W;
int SR, SC, FR, FC;
char board[1010][1010];
int visited[1010][1010];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct Data {
    int r,c;
};

bool CheckWalls(int _r, int _c, int dir) {
    if(dir == 0) {
        if(_r-1 <= 0) return false;
        for(int c = _c; c < _c + W; c++) {
            if(board[_r-1][c] == '1') return false;
        }
    }
    else if(dir == 1) {
        if(_c+W > M) return false;
        for(int r = _r; r < _r + H; r++) {
            if(board[r][_c+W] == '1') return false;
        }
    }
    else if(dir == 2) {
        if(_r+H > N) return false;
        for(int c = _c; c < _c + W; c++) {
            if(board[_r+H][c] == '1') return false;
        }
    } else {
        if(_c-1 <= 0) return false;
        for(int r = _r; r < _r +H; r++) {
            if(board[r][_c-1] == '1') return false;
        }
    }
    return true;
}

bool bfs() {
    queue<Data> q;
    q.push({SR, SC});
    visited[SR][SC] = 0;

    while (!q.empty()) {
        int r = q.front().r, c = q.front().c;
        q.pop();
//        cout << r << ',' << c << endl;
        if (r == FR && c == FC) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            if (CheckWalls(r, c, i)) {
                int nr = r + dr[i], nc = c + dc[i];
//                cout << "CHECKED " << nr << ',' << nc << ' ' << i << endl;
                if (visited[nr][nc] > visited[r][c] + 1) {
                    q.push({nr, nc});
                    visited[nr][nc] = visited[r][c] + 1;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
            visited[i][j] = INF;
        }
    }
    cin >> H >> W >> SR >> SC >> FR >> FC;

    if(bfs()) {
        cout << visited[FR][FC];
    } else {
        cout << -1;
    }

}