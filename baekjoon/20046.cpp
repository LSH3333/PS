#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 100000000
int R, C;
int board[1010][1010];
int d[1010][1010];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct Data {
    int r, c;
    int cost;
};

struct cmp {
    bool operator()(const Data &a, const Data &b) {
        return a.cost > b.cost;
    }
};

void bfs() {
    priority_queue<Data, vector<Data>, cmp> pq;
    pq.push({0, 0, board[0][0]});
    d[0][0] = board[0][0];

    while (!pq.empty()) {
        int r = pq.top().r, c = pq.top().c, cost = pq.top().cost;
        pq.pop();

        if(d[r][c] < cost) continue;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || board[nr][nc] == -1) continue;
            int nextCost = cost + board[nr][nc];
            if (nextCost < d[nr][nc]) {
                d[nr][nc] = nextCost;
                pq.push({nr, nc, nextCost});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
            d[i][j] = INF;
        }
    }

    if(board[0][0] == -1) {
        cout << -1;
        return 0;
    }

    bfs();

    if(d[R-1][C-1] == INF) {
        cout << -1;
    }else {
        cout << d[R-1][C-1];
    }
}