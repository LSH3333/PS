#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define VERT 0
#define HORZ 1
#define INF 10000000

int N;
// [r][c][dir] : dir ?????? (r,c) ? ??, (r,c)?? ????? ????
int cost[30][30][4];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct Data {
    int r, c, money, direction;
};

void bfs(const vector<vector<int>> &board) {
    queue<Data> q;
    q.push({0, 0, 0, -1});
    cost[0][0][0] = 0;

    while (!q.empty()) {
        int r = q.front().r, c = q.front().c;
        int money = q.front().money, direction = q.front().direction;
        q.pop();

        for(int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir], nc = c + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(board[nr][nc] == 1) continue;


            int nextMoney = money;
            if(direction == HORZ) {
                if(dir == 0 || dir == 2) {
                    nextMoney += 500 + 100;
                } else {
                    nextMoney += 100;
                }
            } else if (direction == VERT) {
                if(dir == 0 || dir == 2) {
                    nextMoney += 100;
                } else {
                    nextMoney += 500 + 100;
                }
            } else { // -1
                nextMoney += 100;
            }

            if (cost[nr][nc][dir] > nextMoney) {
                cost[nr][nc][dir] = nextMoney;
                if(dir == 0 || dir == 2) {
                    q.push({nr, nc, nextMoney,  VERT});
                } else {
                    q.push({nr, nc, nextMoney,  HORZ});
                }
            }
        }
    }
}

void Init() {
    for(int i = 0; i < 30; i++) {
        for(int j = 0; j < 30; j++) {
            for(int d = 0; d < 4; d++) {
                cost[i][j][d] = INF;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    N = (int)board.size();
    Init();

    bfs(board);


    int answer = INF;

    for(int i = 0; i < 4; i++) {
        answer = min(answer, cost[N - 1][N - 1][i]);
    }

    return answer;
}

int main() {
    vector<vector<int>> board = {
            {0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 1, 0},
            {0, 1, 0, 0, 0, 1, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0}
    };
    solution(board);
}