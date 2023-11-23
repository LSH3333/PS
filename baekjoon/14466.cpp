#include <iostream>
#include <vector>
using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
int N, K, R;
bool road[101][101][4];
int noCross;
int cows[101][101];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

void dfs(int _r, int _c, vector<vector<bool>> &visited, int cowNum) {
    for(int i = 0; i < 4; i++) {
        int nr = _r + dr[i], nc = _c + dc[i];
        if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
        // ?? ?? ?? || ?? ??
        if(road[_r][_c][i] || visited[nr][nc]) continue;
        if(cows[nr][nc] != 0 && cows[nr][nc] > cowNum) noCross++; // ? ??? ?? ??? ?? ?
        visited[nr][nc] = true;
        dfs(nr, nc, visited, cowNum);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> R;
    for(int i = 0; i < R; i++) {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;

        if(r1>r2 && c1==c2) {
            road[r1][c1][UP] = true;
            road[r2][c2][DOWN] = true;
        } else if(r1==r2 && c1<c2) {
            road[r1][c1][RIGHT] = true;
            road[r2][c2][LEFT] = true;
        } else if(r1<r2 && c1==c2) {
            road[r1][c1][DOWN] = true;
            road[r2][c2][UP] = true;
        } else {
            road[r1][c1][LEFT] = true;
            road[r2][c2][RIGHT] = true;
        }
    }

    vector<pair<int,int>> cowLoc;
    for(int i = 1; i <= K; i++) {
        int r,c; cin >> r >> c;
        cows[r][c] = i;
        cowLoc.push_back({r, c});
    }


    for(int i = 1; i <= K; i++) {
        int r = cowLoc[i-1].first, c = cowLoc[i-1].second;
        vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
        visited[r][c] = true;
        dfs(r,c,visited, i);
    }

    int totalPairs = 0;
    for(int i = K-1; i > 0; i--) {
        totalPairs += i;
    }

    cout << totalPairs-noCross;
}