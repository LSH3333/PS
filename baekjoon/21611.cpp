#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[50][50];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int ans[4];

vector<pair<int,int>> visitOrder;
bool visited[50][50];
void dfs(int r, int c, int dir) {
    if (r == (N + 1) / 2 && c == (N + 1) / 2) {
        return;
    }
    visited[r][c] = true;
    int nr = r + dr[dir], nc = c + dc[dir];

    if(nr < 1 || nr > N || nc < 1 || nc > N || visited[nr][nc]) {
        int nDir = (dir + 1) % 4;
        dfs(r+dr[nDir], c+dc[nDir], (dir + 1) % 4);
    } else {
        dfs(nr, nc, dir);
    }

    visitOrder.push_back({r, c});

}

void Print() {
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cout << board[r][c] << ' ';
        } cout << endl;
    } cout << endl;
}

void MoveMarbles() {
    for(int i = 0; i < visitOrder.size()-1; i++) {
        int r = visitOrder[i].first, c = visitOrder[i].second;
        int nr = visitOrder[i+1].first, nc = visitOrder[i+1].second;

        if(board[r][c] == 0) {
            board[r][c] = board[nr][nc];
            board[nr][nc] = 0;
        }
    }
}

int bl_dr[] = {0, -1, 1, 0, 0};
int bl_dc[] = {0, 0, 0, -1, 1};
void Blizzard(int d, int s) {
    int r = (N+1)/2, c = (N+1)/2;
    for(int i = 1; i <= s; i++) {
        int nr = r + bl_dr[d] * i;
        int nc = c + bl_dc[d] * i;
        board[nr][nc] = 0;
    }
}

// ?? 4? ???? ????? ?? ??
int Explode() {
    int explodeCnt = 0;

    int i = 0;
    while (i < visitOrder.size()) {
        if(board[visitOrder[i].first][visitOrder[i].second] == 0) break;
        int flag = board[visitOrder[i].first][visitOrder[i].second];
        int cnt = 0;
        int j;
        // 0 ?? ?? ???
        for(j = i; j < visitOrder.size(); j++) {
            int r = visitOrder[j].first, c = visitOrder[j].second;
            if(board[r][c] == flag) {
                cnt++;
            } else {
                j--;
                break;
            }
        }

        // ?? 4? ???? ??
        if(cnt >= 4) {
            for(int idx = i; idx <= j; idx++) {
                int marble = board[visitOrder[idx].first][visitOrder[idx].second];
                ans[marble]++;

                board[visitOrder[idx].first][visitOrder[idx].second] = 0;
                explodeCnt++;
            }
        }

        i = j+1;
    }

    // ?? ?? ? ??
    for(i = 0; i < explodeCnt; i++) {
        MoveMarbles();
    }
    return explodeCnt;
}

void Transform() {
    vector<int> v;
    int i = 0;

    while (i < visitOrder.size()) {
        if(board[visitOrder[i].first][visitOrder[i].second] == 0) break;
        int flag = board[visitOrder[i].first][visitOrder[i].second];
        int cnt = 0;
        int j;

        for(j = i; j < visitOrder.size(); j++) {
            int r = visitOrder[j].first, c = visitOrder[j].second;
            if(board[r][c] == flag) {
                cnt++;
            } else {
                j--;
                break;
            }
        }

        v.push_back(cnt);
        v.push_back(flag);
        i = j+1;
    }

    for(i = 0; i < v.size() && i < visitOrder.size(); i++) {
        int r = visitOrder[i].first, c = visitOrder[i].second;
        board[r][c] = v[i];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> board[r][c];
        }
    }

    dfs(1,1,0);

    for(int i = 0; i < M; i++) {
        int d, s; cin >> d >> s;
        // ????
        Blizzard(d, s);

        // ?? ??
        for(int j = 0; j < s; j++) {
            MoveMarbles();
        }

        // ???? ?? ?? ??? ?? -> ?? ??
        while(Explode() > 0) {}

        // ?? ?? ??
        Transform();
    }

    int answer = ans[1] + ans[2]*2 + ans[3]*3;
    cout << answer;
}