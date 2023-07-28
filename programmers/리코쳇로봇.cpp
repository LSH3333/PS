#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define INF 10000000

int N, M, answer;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int visited[110][110];

pair<int,int> MoveDir(int dir, int r, int c, const vector<string> &board) {
    while(true) {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == 'D') {
            return { r, c };
        }
        r = nr; c = nc;
    }
}

void dfs(int _r, int _c, int depth, const vector<string> &board) {
    if (board[_r][_c] == 'G') {
        answer = min(answer, depth);
        return;
    }

    for(int i = 0; i < 4; i++) {
        pair<int,int> next = MoveDir(i, _r, _c, board);
        int nr = next.first, nc = next.second;
        if(visited[nr][nc] < depth+1) continue;
        visited[nr][nc] = depth+1;
        dfs(nr, nc, depth+1, board);
    }
}


int solution(vector<string> board) {
    answer = INF;
    N = (int)board.size();
    M = (int) board.front().size();
    int robotR, robotC;

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.front().size(); j++) {
            if (board[i][j] == 'R') {
                robotR = i; robotC = j;
                board[i][j] = '.';
            }
            visited[i][j] = INF;
        }
    }

    dfs(robotR, robotC, 0, board);


    if(answer == INF) {
        answer = -1;
    }
    return answer;
}

int main() {
    vector<string> board = {"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};
    cout << solution(board);
}