#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 1000000
int dr[] = {-1, 0, 1, 0};
int dc[] = {0,1,0,-1};


int Dijkstra(int N, const vector<vector<int>> &board) {
    vector<vector<int>> mark(N, vector<int>(N, INF));
    // distance, {r, c}
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
    pq.push({board[0][0], {0, 0}});
    mark[0][0] = board[0][0];

    while (!pq.empty()) {
        int r = pq.top().second.first, c = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        if(mark[r][c] < cost) continue;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            int nextCost = cost + board[nr][nc];
            if(mark[nr][nc] > nextCost) {
                mark[nr][nc] = nextCost;
                pq.push({nextCost, {nr, nc}});
            }
        }
    }

    return mark[N-1][N-1];
}

int main() {
//    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T = 1;
    while(true) {
        int N;
        cin >> N;
        if(N == 0) return 0;

        vector<vector<int>> board(N, vector<int>(N));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }


        int res = Dijkstra(N, board);
        cout << "Problem " << T++ << ": " << res << '\n';
    }

}