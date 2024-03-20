#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Data {
    int a,b,c;
    int cnt;
};

int N;
int damage[][3]= {{9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9}};
int d[61][61][61];

void Init() {
    for(int i = 0; i < 61; i++) {
        for(int j = 0; j < 61; j++) {
            for(int k = 0; k < 61; k++) {
                d[i][j][k] = 10000000;
            }
        }
    }
}

void bfs(int _a, int _b, int _c) {
    queue<Data> q;
    q.push({_a, _b, _c, 0});
    d[_a][_b][_c] = 0;

    while (!q.empty()) {
        int a = q.front().a, b = q.front().b, c = q.front().c;
        int cnt = q.front().cnt;
        q.pop();

        for(int i = 0; i < 6; i++) {
            int na = a - damage[i][0] >= 0 ? a - damage[i][0] : 0;
            int nb = b - damage[i][1] >= 0 ? b - damage[i][1] : 0;
            int nc = c - damage[i][2] >= 0 ? c - damage[i][2] : 0;

            if (d[na][nb][nc] > cnt + 1) {
                d[na][nb][nc] = cnt + 1;
                q.push({na, nb, nc, cnt + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Init();

    cin >> N;
    int a=0,b=0,c=0;
    if(N == 1) {
        cin >> a;
    } else if(N == 2) {
        cin >> a >> b;
    }else {
        cin >> a >> b >> c;
    }

    bfs(a, b, c);

    cout << d[0][0][0];
}