#include <iostream>
#include <vector>
using namespace std;

#define MAX 110
int C, P;
int board[120][120];

struct Shape {
    vector<vector<pair<int,int>>> loc;
};
Shape shapes[8];

void MakeShapes() {
    shapes[1].loc.push_back({{0,0},{1,0},{2,0},{3,0}});
    shapes[1].loc.push_back({{0,0},{0,1},{0,2},{0,3}});

    shapes[2].loc.push_back({{0,0},{0,1},{1,0},{1,1}});

    shapes[3].loc.push_back({{0,1},{0,2},{1,0},{1,1}});
    shapes[3].loc.push_back({{0,0},{1,0},{1,1},{2,1}});

    shapes[4].loc.push_back({{0,0},{0,1},{1,1},{1,2}});
    shapes[4].loc.push_back({{0,1},{1,0},{1,1},{2,0}});

    shapes[5].loc.push_back({{0,1},{1,0},{1,1},{1,2}});
    shapes[5].loc.push_back({{0,0},{1,0},{2,0},{1,1}});
    shapes[5].loc.push_back({{0,0},{0,1},{0,2},{1,1}});
    shapes[5].loc.push_back({{0,1},{1,1},{2,1},{1,0}});

    shapes[6].loc.push_back({{0,2},{1,0},{1,1},{1,2}});
    shapes[6].loc.push_back({{0,0},{1,0},{2,0},{2,1}});
    shapes[6].loc.push_back({{0,0},{0,1},{0,2},{1,0}});
    shapes[6].loc.push_back({{0,0},{0,1},{1,1},{2,1}});

    shapes[7].loc.push_back({{0,0},{1,0},{1,1},{1,2}});
    shapes[7].loc.push_back({{0,0},{0,1},{1,0},{2,0}});
    shapes[7].loc.push_back({{0,0},{0,1},{0,2},{1,2}});
    shapes[7].loc.push_back({{0,1},{1,1},{2,1},{2,0}});
}

void Restore(const vector<pair<int,int>> &v) {
    for(auto x : v) {
        board[x.first][x.second] = 0;
    }
}

bool TryShape(int _r, int _c, const vector<pair<int,int>> &loc) {
    vector<pair<int,int>> v;
    // ?? ????? ??? ???? ??
    for(auto x : loc) {
        int r = _r + x.first, c = _c + x.second;
        if(r < 0 || r > MAX || c < 0 || c >= C) return false;
        if(board[r][c] == 1) return false;
        v.push_back({r, c});
    }

    for(auto x : v) {
        board[x.first][x.second] = 1;
    }


    // ?? ??? ??
    for(auto x : v) {
        for(int r = x.first+1; r <= MAX; r++) {
            if(board[r][x.second] != 1) {
                Restore(v);
                return false;
            }
        }
    }
    Restore(v);
    return true;
}

int TryShapeAllPlace(const vector<pair<int,int>> &loc) {
    int cnt = 0;
    for(int r = 0; r <= MAX; r++) {
        for(int c = 0; c < C; c++) {
            if (TryShape(r, c, loc)) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    MakeShapes();

    cin >> C >> P;
    for(int i = 0; i < C; i++) {
        int h; cin >> h;
        for(int j = MAX; j > MAX-h; j--) {
            board[j][i] = 1;
        }
    }


    int answer = 0;
    for (const auto &x : shapes[P].loc) {
        answer += TryShapeAllPlace(x);
    }

    cout << answer;
}