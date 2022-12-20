#include <iostream>
#include <vector>
using namespace std;

int N, M;
int answer;
char board[51][51];

int Cal(const vector<int> &v) {
    char newBoard[51][51];
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            newBoard[r][c] = board[r][c];
        }
    }

    for(auto col : v) {
        for(int r = 0; r < N; r++) {
            board[r][col] == '0' ? newBoard[r][col] = '1' : newBoard[r][col] = '0';
        }
    }

    int cnt = 0;
    for(int r = 0; r < N; r++) {
        bool bingo = true;
        for(int c = 0; c < M; c++) {
            if(newBoard[r][c] == '0') {bingo = false; break;}
        }
        if(bingo) cnt++;
    }

    return cnt;
}


// 특정 열 뒤집을지 말지만 결정
bool mark[51];
void dfs(int idx, int depth, vector<int> &v, int K) {
    if(depth == K) {
        for(auto x : v) cout << x << ' '; cout << endl;
        int res = Cal(v);
        answer = max(answer, res);
        return;
    }

    for(int i = idx; i < M; i++) {
        if(mark[i]) continue;
        mark[i] = true;
        v.push_back(i);
        dfs(i, depth+1, v, K);
        v.pop_back();
        mark[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    cin >> K;

    vector<int> v;
    if(K > M) {
        if(K % 2 != 0) {
            if(M % 2 == 0) {
                dfs(0, 0, v, M-1);
            }
            else {
                dfs(0, 0, v, M);
            }
        }
        else { // K % 2 == 0
            if(M % 2 == 0) {
                dfs(0, 0, v, M);
            }
            else {
                dfs(0, 0, v, M-1);
            }
        }
    }
    else {
        dfs(0, 0, v, K);
    }



    cout << answer;
}