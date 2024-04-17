#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000
int N, M, A, B, K;
bool board[510][510];
int d[510][510];
int sr, sc, er, ec;

bool CheckUp(int _r, int _c) {
    for(int c = _c; c < _c + B; c++) {
        if(board[_r-1][c]) return false;
    }
    return true;
}

bool CheckRight(int _r, int _c) {
    for(int r = _r; r < _r + A; r++) {
        if(board[r][_c+B]) return false;
    }
    return true;
}

bool CheckDown(int _r, int _c) {
    for(int c = _c; c < _c + B; c++) {
        if(board[_r+A][c]) return false;
    }
    return true;
}

bool CheckLeft(int _r, int _c) {
    for(int r = _r; r < _r + A; r++) {
        if(board[r][_c-1]) return false;
    }
    return true;
}

int bfs() {
    queue<pair<int,int>> q;
    q.push({sr, sc});
    d[sr][sc] = 0;

    while (!q.empty()) {
        int _r = q.front().first;
        int _c = q.front().second;
        q.pop();

        if(_r == er && _c == ec) {
            return d[_r][_c];
        }

        // up
        if(_r - 1 >= 1 && CheckUp(_r, _c) && d[_r-1][_c] > d[_r][_c] + 1) {
            d[_r - 1][_c] = d[_r][_c] + 1;
            q.push({_r - 1, _c});
        }
        // right
        if(_c + B <= M && CheckRight(_r,_c) && d[_r][_c+1] > d[_r][_c] + 1) {
            d[_r][_c+1] = d[_r][_c] + 1;
            q.push({_r, _c + 1});
        }
        // down
        if (_r + A <= N && CheckDown(_r, _c) && d[_r + 1][_c] > d[_r][_c] + 1) {
            d[_r+1][_c] = d[_r][_c] + 1;
            q.push({_r + 1, _c});
        }
        // left
        if (_c - 1 >= 1 && CheckLeft(_r, _c) && d[_r][_c - 1] > d[_r][_c] + 1) {
            d[_r][_c - 1] = d[_r][_c] + 1;
            q.push({_r, _c - 1});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> A >> B >> K;
    for(int i = 0; i < K; i++) {
        int r,c; cin >> r >> c;
        board[r][c] = true;
    }

    cin >> sr >> sc;
    cin >> er >> ec;

    for(int i = 0; i < 510; i++) {
        for(int j = 0; j < 510; j++) {
            d[i][j] = INF;
        }
    }

    cout << bfs();


}