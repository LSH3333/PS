#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int mp, mf, ms, mv;
int board[20][5];
bool visited[20];
vector<pair<int, vector<int>>> answer;


void dfs(int _r, int goalDepth, int p, int f, int s, int v, int cost, int idx) {
    if(_r > goalDepth){
        if(p >= mp && f >= mf && s >= ms && v >= mv) {
            vector<int> list;
            for(int i = 1; i <= N; i++) {
                if(visited[i])  {
                    list.push_back(i);
                }
            }

            answer.push_back({cost, list});
        }

        return;
    }

    for(int r = idx; r <= N; r++) {
        if(visited[r]) continue;
        visited[r] = true;
        dfs(r + 1, goalDepth, p + board[r][0], f + board[r][1], s + board[r][2], v + board[r][3], cost+board[r][4], r+1);
        visited[r] = false;
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for(int goalDepth = N; goalDepth >= 1; goalDepth--) {
        dfs(1, goalDepth, 0, 0, 0, 0, 0, 1);
    }

    sort(answer.begin(), answer.end());

    if(answer.empty()) {
        cout << -1;
    } else {
        cout << answer.front().first << '\n';
        for (auto x: answer.front().second) {
            cout << x << ' ';
        }
    }

}