#include <iostream>
using namespace std;

char board[10][10];
bool mark[10][10];
int paper[10]; // 1 ~ 5 색종이 갯수
int answer = 10000;
int totalOne;
int coveredOne;

pair<int,int> GetNextPos(int r, int c) {
    if(c+1 >= 10) {
        r = r + 1;
        c = 0;
    }
    else {
        c = c + 1;
    }

    return {r, c};
}

// (_r,_c) 에서 len 크기 만큼 정사각형 1 인지 확인
bool Check(int _r, int _c, int len) {
    if(_r+len-1 >= 10 || _c+len-1 >= 10) return false;
    for(int r = _r; r < _r+len; r++) {
        for(int c = _c; c < _c+len; c++) {
            if(board[r][c] == '0' || mark[r][c]) return false;
        }
    }
    return true;
}

void MarkMark(int _r, int _c, int len, bool makeTrue) {
    for(int r = _r; r < _r+len; r++) {
        for(int c = _c; c < _c+len; c++) {
            if(makeTrue) mark[r][c] = true;
            else mark[r][c] = false;
        }
    }
}

int CountPaper() {
    int sum = 0;
    for(int i = 1; i <= 5; i++) {
        sum += paper[i];
    }
    return 25-sum;
}

void dfs(int _r, int _c) {
    pair<int,int> nextPos = GetNextPos(_r, _c);
    // 종료
    if(_r >= 10) {
        if(coveredOne == totalOne) {
            answer = min(answer, CountPaper());
        }
        return;
    }

//    cout << _r << ',' << _c << endl;
//    for(int i = 1; i <= 5; i++) cout << paper[i] << ' '; cout<<endl;
//    cout << "ans: " << answer << endl;
//    for(int i = 0; i < 10; i++) {
//        for(int j = 0; j < 10; j++) {
//            cout << mark[i][j] << ' ';
//        } cout << endl;
//    } cout << endl;

    // skip
    if(board[_r][_c] == '0' || mark[_r][_c]) {
        dfs(nextPos.first, nextPos.second);
    }
    // 색종이 붙임
    else {
        for(int len = 5; len >= 1; len--) {
            if(paper[len] > 0 && Check(_r, _c, len)) {
                paper[len]--;
                MarkMark(_r, _c, len, true);
                coveredOne += len * len;
                dfs(nextPos.first, nextPos.second);
                coveredOne -= len * len;
                paper[len]++;
                MarkMark(_r, _c, len, false);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> board[i][j];
            if(board[i][j] == '1') totalOne++;
        }
    }

    for(int i = 0; i < 10; i++) {
        paper[i] = 5;
    }

    dfs(0, 0);

    if(answer == 10000) cout << -1;
    else cout << answer;
}