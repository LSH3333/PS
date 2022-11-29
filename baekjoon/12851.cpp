#include <iostream>
#include <queue>
using namespace std;

int N, K;
int mark[200011];
int cnt;
bool found;

void bfs() {
    queue<pair<int,int>> q;
    mark[N] = 0;
    q.push({N, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
//        cout << cur << ' ' << depth << endl;

        if(!found && cur == K) {
            found = true;
            cnt = 1;
            continue;
        }
        else if(found && cur == K) {
            cnt++;
            continue;
        }

        if(found && depth >= mark[K]) continue;

        if(cur*2 <= 200010 && mark[cur*2] >= depth+1) {
            mark[cur*2] = depth+1;
            q.push({cur * 2, depth+1});
        }
        if(cur-1 >= 0 && mark[cur-1] >= depth+1) {
            mark[cur-1] = depth+1;
            q.push({cur - 1, depth+1});
        }
        if(cur+1 <= 200010 && mark[cur+1] >= depth+1) {
            mark[cur+1] = depth+1;
            q.push({cur + 1, depth + 1});
        }
    }
}

int main() {
    cin >> N >> K;
    for(int i = 0; i < 200011; i++) {
        mark[i] = 100001;
    }
    bfs();

    cout << mark[K] << '\n' << cnt;
}