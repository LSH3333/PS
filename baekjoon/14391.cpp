#include <iostream>
using namespace std;

#define HOR 0
#define VER 1

int N, M;
int answer;
char board[5][5];
bool mark[5][5];


bool Check(int _r, int _c, int len, int dir) {
    if(dir == VER) {
        if(_r+len-1 >= N) return false;
        for(int r = _r; r < _r+len; r++) {
            if(mark[r][_c]) return false;
        }
        return true;
    }
    else {
        if(_c+len-1 >= M) return false;
        for(int c = _c; c < _c+len; c++) {
            if(mark[_r][c]) return false;
        }
        return true;
    }
}

int Fill(int _r, int _c, int len, int dir, bool fill) {
    string number;

    // 가로 조각
    if(dir == HOR) {
        for(int c = _c; c < _c + len; c++) {
            if(fill) {
                number.push_back(board[_r][c]);
                mark[_r][c] = true;
            }
            else mark[_r][c] = false;
        }
    }
    // 세로 조각
    else {
        for(int r = _r; r < _r + len; r++) {
            if(fill) {
                number.push_back(board[r][_c]);
                mark[r][_c] = true;
            }
            else mark[r][_c] = false;
        }
    }
    
    if(fill) return stoi(number);
    else return 0;
}

pair<int,int> FindNextPos() {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(!mark[r][c]) {
                return {r, c};
            }
        }
    }
    // 모두 채워짐
    return {-1, -1};
}


void dfs(int _r, int _c, int sum) {
    // 완성
    if(_r == -1 && _c == -1) {
        answer = max(answer, sum);
        return;
    }
    for(int len = 1; len <= 4; len++) {
        // HOR
        if (Check(_r, _c, len, HOR)) {
            int number = Fill(_r, _c, len, HOR, true);
            auto next = FindNextPos();
            dfs(next.first, next.second, sum+number);
            Fill(_r, _c, len, HOR, false);
        }

        if (Check(_r, _c, len, VER)) {
            int number = Fill(_r, _c, len, VER, true);
            auto next = FindNextPos();
            dfs(next.first, next.second, sum+number);
            Fill(_r, _c, len, VER, false);
        }

    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0);

    cout << answer;
}