#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 20
#define INF 1000000

int N, answer;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct Fish {
    int r, c, size, distance;
};
struct Shark {
    int r,c,size, eatenCnt;
};

Fish board[MAX+1][MAX+1];


void CalDistance(const Shark &shark) {
    vector<vector<bool>> visited(MAX+1, vector<bool>(MAX+1, false));
    queue<pair<pair<int,int>,int>> q;

    visited[shark.r][shark.c] = true;
    q.push({{shark.r, shark.c}, 0});

    while (!q.empty()) {
        int r = q.front().first.first, c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(visited[nr][nc] || board[nr][nc].size > shark.size) continue;
            visited[nr][nc] = true;
            board[nr][nc].distance = depth + 1;
            q.push({{nr, nc}, depth + 1});
        }
    }
}


bool cmp(const Fish* a, const Fish* b) {
    if (a->distance == b->distance) {
        if (a->r == b->r) {
            return a->c < b->c;
        }
        return a->r < b->r;
    }
    return a->distance < b->distance;
}

void EatFish(Shark &shark, Fish &fish) {
    // ? ?? ? ? ??
    answer += fish.distance;
    // ?? ??
    shark.r = fish.r;
    shark.c = fish.c;
    // ?? ??
    shark.eatenCnt++;
    if(shark.eatenCnt == shark.size) {
        shark.eatenCnt = 0;
        shark.size++;
    }
    // Fish ?? ??
    fish.size = 0;
}

bool StartMoving(Shark &shark) {
    CalDistance(shark);

    // ??? ?? ??? ??
    vector<Fish*> eatable;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(board[r][c].size != 0 && board[r][c].size < shark.size) {
                eatable.push_back(&board[r][c]);
            }
        }
    }

    sort(eatable.begin(), eatable.end(), cmp);

    if(eatable.empty() || eatable.front()->distance == INF) {
        return false;
    }

    EatFish(shark, *eatable.front());

    return true;
}



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Shark shark{0,0,2,0};

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int n; cin >> n;
            // shark
            if(n == 9) {
                shark.r = i;
                shark.c = j;
                shark.size = 2;
            }
                // fish
            else if(n >= 1 && n <= 6) {
                Fish fish{i, j, n, INF};
                board[i][j] = fish;
            }
                // empty
            else {
                board[i][j] = Fish{0, 0, 0, 0};
            }
        }
    }

    while(StartMoving(shark));

    cout << answer;

}