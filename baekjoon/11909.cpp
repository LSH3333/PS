#include <iostream>
#include <queue>
using namespace std;

#define INF 100000000
int N;
int board[2230][2230];
int d[2230][2230];
int dr[] = {0, 1};
int dc[] = {1, 0};
int answer = INF;

struct Data {
    int r, c;
    int distance;
};

struct cmp {
    bool operator()(const Data &a, const Data &b) {
        return a.distance > b.distance;
    }
};

void Dijkstra() {
    priority_queue<Data, vector<Data>, cmp> pq;
    pq.push({0, 0, 0});
    d[0][0] = 0;

    while (!pq.empty()) {
        int r = pq.top().r, c = pq.top().c;
        int dist = pq.top().distance;
        pq.pop();

        if(d[r][c] < dist) continue;

        for(int i = 0; i < 2; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= N || nc >= N) continue;
            int addDist = board[nr][nc] - board[r][c] < 0 ? 0 : board[nr][nc] - board[r][c] + 1;
            int nextDist = dist + addDist;
            if (nextDist < d[nr][nc]) {
                d[nr][nc] = nextDist;
                pq.push({nr, nc, nextDist});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            d[i][j] = INF;
        }
    }

    Dijkstra();

    cout << d[N-1][N-1];
}