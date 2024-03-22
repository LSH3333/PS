#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 100000000
#define MAX 500
int N, M;
char board[MAX+1][MAX+1];
bool visited[4][MAX+1][MAX+1];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
char dir[] = {'U', 'R', 'D', 'L'};
int maxDepth;

void Init() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            visited[0][i][j] = false;
            visited[1][i][j] = false;
            visited[2][i][j] = false;
            visited[3][i][j] = false;
        }
    }
}

void dfs(int r, int c, int depth, int prevDir) {
    if (board[r][c] == 'C' || r <= 0 || r > N || c <= 0 || c > M) {
        maxDepth = max(maxDepth, depth);
        return;
    }
    // ???
    if (visited[prevDir][r][c]) {
        maxDepth = INF;
        return;
    }
    visited[prevDir][r][c] = true;

//    cout << r << ',' << c << ' ' << "prevDir: " << prevDir << endl;

    // '/' ??
    if (board[r][c] == '/') {
        int nr, nc;
        if(prevDir == 0) {
            nr = r; nc = c + 1;
            dfs(nr, nc, depth + 1, 1);
        } else if(prevDir == 1) {
            nr = r - 1; nc = c;
            dfs(nr, nc, depth + 1, 0);
        } else if(prevDir == 2) {
            nr = r; nc = c - 1;
            dfs(nr, nc, depth + 1, 3);
        } else {
            nr = r + 1; nc = c;
            dfs(nr, nc, depth + 1, 2);
        }
    }
        // '\' ??
    else if (board[r][c] == '\\') {
        int nr, nc;
        if(prevDir == 0) {
            nr = r; nc = c - 1;
            dfs(nr, nc, depth + 1, 3);
        } else if(prevDir == 1) {
            nr = r + 1; nc = c;
            dfs(nr, nc, depth + 1, 2);
        } else if(prevDir == 2) {
            nr = r; nc = c + 1;
            dfs(nr, nc, depth + 1, 1);
        } else {
            nr = r - 1; nc = c;
            dfs(nr, nc, depth + 1, 0);
        }
    }
    else {
        int nr = r + dr[prevDir], nc = c + dc[prevDir];
        dfs(nr, nc, depth + 1, prevDir);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int pr,pc;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    cin >> pr >> pc;

    vector<int> depths(4);
    for(int i = 0; i < 4; i++) {
        maxDepth = 0;
        dfs(pr, pc, 0, i);
        depths[i] = maxDepth;
        Init();
    }


    int maxAns = 0;
    for(int i = 0; i < 4; i++) {
        maxAns = max(maxAns, depths[i]);
    }

    for(int i = 0; i < 4; i++) {
        if(depths[i] == maxAns) {
            cout << dir[i] << '\n';
            if(maxAns == INF) {
                cout << "Voyager";
            } else {
                cout << maxAns;
            }
            break;
        }
    }


}