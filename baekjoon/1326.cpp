#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int arr[10010];
int d[10010];
int a, b;
#define INF 100000000

void bfs() {
    queue<int> q;
    q.push(a);
    d[a] = 0;


    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // right
        int num = arr[cur], j = 1;
        int next = cur + (num * j);
        while(next <= N) {
            if (d[next] > d[cur] + 1) {
                d[next] = d[cur] + 1;
                q.push(next);
            }
            next = cur + (num * ++j);
        }
        // left
        j = 1;
        next = cur - (num * j);
        while(next > 0) {
            if(d[next] > d[cur] + 1) {
                d[next] = d[cur] + 1;
                q.push(next);
            }
            next = cur - (num * ++j);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        d[i] = INF;
    }
    cin >> a >> b;

    bfs();

    if(d[b] == INF) {
        cout << -1;
    } else {
        cout << d[b];
    }
}