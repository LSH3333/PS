#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int islandCnt;
int board[11][11];
vector<vector<int>> edges;
int parent[7];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


void bfs(int _r, int _c, int island) {
    queue<pair<int,int>> q;
    q.push({_r, _c});
    board[_r][_c] = island;

    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] != -1) continue;
            board[nr][nc] = island;
            q.push({nr, nc});
        }
    }
}

void GiveNumberToIslands() {
    int island = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (board[i][j] == -1) {
                bfs(i, j, island++);
            }
        }
    }
    islandCnt = island - 1;
}

void BuildBridge(int r, int c, int dir, int island) {
    int len = 0;
    int nr = r + dr[dir], nc = c + dc[dir];
    while(nr >= 0 && nr < N && nc >= 0 && nc <= M && board[nr][nc] != island) {
        // ?? ? ??
        if(board[nr][nc] != 0) {
            // ?? ??? 2 ??
            if(len >= 2) {
                edges.push_back({len, island, board[nr][nc]});
            }
            break;
        }
        nr = nr + dr[dir];
        nc = nc + dc[dir];
        len++;
    }
}

void BuildBridgeFromIsland(int island, int r, int c) {
    BuildBridge(r, c, 0, island);
    BuildBridge(r, c, 1, island);
    BuildBridge(r, c, 2, island);
    BuildBridge(r, c, 3, island);
}

void BuildBridges() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] > 0) {
                BuildBridgeFromIsland(board[i][j], i, j);
            }
        }
    }
}

int GetParent(int node) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = GetParent(parent[node]);
}

bool IsParentSame(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    return node1 == node2;
}

void Union(int node1, int node2) {
    node1 = GetParent(node1);
    node2 = GetParent(node2);
    parent[max(node1, node2)] = min(node1, node2);
}

int Kruskal() {
    int answer = 0, connectedCnt = 0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i <= islandCnt; i++) {
        parent[i] = i;
    }

    for(auto x : edges) {
        int len = x[0], island1 = x[1], island2 = x[2];

        if (!IsParentSame(island1, island2)) {
            answer += len;
            connectedCnt++;
            Union(island1, island2);
        }
    }

    // ????+1 == ???? ?? Spanning tree ??
    if(connectedCnt != islandCnt - 1) {
        answer = -1;
    }
    return answer;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) {
                board[i][j] = -1;
            }
        }
    }


    GiveNumberToIslands();
    BuildBridges();


    cout << Kruskal();

}