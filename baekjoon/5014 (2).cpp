#include <iostream>
#include <queue>
using namespace std;

#define INF 100000000
#define MAX 1000000

int F,S,G,U,D;
int mark[MAX + 1];

int bfs() {
    queue<int> q;
    mark[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if(cur == G) {
            return mark[cur];
        }

        if(cur + U <= F && mark[cur + U] > mark[cur] + 1) {
            mark[cur + U] = mark[cur] + 1;
            q.push(cur + U);
        }
        if(cur - D >= 1 && mark[cur - D] > mark[cur] + 1) {
            mark[cur-D] = mark[cur] + 1;
            q.push(cur - D);
        }
    }

    return -1;
}

int main() {
    cin >> F >> S >> G >> U >> D;
    fill(mark, mark+MAX+1, INF);

    int res = bfs();
    if(res == -1) {
        cout << "use the stairs";
    }
    else {
        cout << res;
    }
}