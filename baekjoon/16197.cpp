#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int ans = 10000;

void Print(const vector<vector<char>> &board) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << board[i][j];
        } cout << '\n';
    }cout<<'\n';
}

// 1: 정상 이동
// 0: 떨어짐
int MoveCoin(const vector<vector<char>> &board, vector<pair<int,int>> &coins, int coinIdx, int dir) {
    if(coins[coinIdx].first == -1) return 1;
    int nr = coins[coinIdx].first + dr[dir];
    int nc = coins[coinIdx].second + dc[dir];

    if(nr < 0 || nr >= N || nc < 0 || nc >= M) {
        coins[coinIdx] = {-1, -1};
        return 0;
    }
    else if(board[nr][nc] == '#') {
        return 1;
    }
    else {
        coins[coinIdx] = {nr, nc};
        return 1;
    }
}


void dfs(vector<vector<char>> &board, vector<pair<int,int>> &coins, int depth) {
    if(depth > 10) return;
    if(coins[0].first == -1 && coins[1].first == -1) return;

    for(int dir = 0; dir < 4; dir++) {
        int fallen = 0;
        vector<pair<int,int>> saveCoins = coins;
        if(MoveCoin(board, coins, 0, dir) == 0) fallen++;
        if(MoveCoin(board, coins, 1, dir) == 0) fallen++;

        if(fallen == 1) {
            ans = min(ans, depth);
            coins = saveCoins;
            return;
        }
        else if(fallen == 2) {
            coins = saveCoins;
            continue;
        }
        else {
            dfs(board, coins, depth+1);
            coins = saveCoins;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    vector<vector<char>> board(N, vector<char>(M));
    vector<pair<int,int>> coins;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'o') {
                board[i][j] = '.';
                coins.push_back({i, j});
            }
        }
    }

    dfs(board, coins, 1);

    if(ans == 10000) cout << -1;
    else cout << ans;

}