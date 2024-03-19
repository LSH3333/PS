#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000
int N, M, A, B;
bool restrict[100001];
int d[100001];

void bfs() {
    queue<int> q;
    q.push(0);
    d[0] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == N) {
            break;
        }

        if (cur+A <= N && !restrict[cur + A] && d[cur + A] > d[cur] + 1) {
            q.push(cur + A);
            d[cur + A] = d[cur] + 1;
        }

        if (cur+B <= N && !restrict[cur + B] && d[cur + B] > d[cur] + 1) {
            q.push(cur + B);
            d[cur + B] = d[cur] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> A >> B;
    for(int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;

        for(int j = a; j <= b; j++) {
            restrict[j] = true;
        }
    }

    for(int i = 0; i < 100001; i++) {
        d[i] = INF;
    }

    bfs();

    if(d[N] == INF) {
        cout << -1;
    } else {
        cout << d[N];
    }
}