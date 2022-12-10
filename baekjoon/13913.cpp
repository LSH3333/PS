#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
int mark[210000];
int previous[210000];

void bfs() {
    // 위치, 경로
    queue<pair<int,int>> q;
    mark[N] = 0;
    q.push({N, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int depth = q.front().second;
        q.pop();

        // 도착
        if (x == K) {
            cout << depth << '\n';
            int i = K;
            vector<int> v = {K};
            while(i != N) {
                v.push_back(previous[i]);
                i = previous[i];
            }
            for(i = (int)v.size()-1; i >= 0; i--) cout << v[i] << ' ';
            return;
        }

        if(x-1 >= 0 && mark[x-1] > depth+1) {
            mark[x-1] = depth + 1;
            previous[x-1] = x;
            q.push({x - 1, depth + 1});
        }
        if(x+1 < 210000 && mark[x+1] > depth+1) {
            mark[x+1] = depth + 1;
            previous[x+1] = x;
            q.push({x + 1, depth + 1});
        }
        if(x*2 < 210000 && mark[x*2] > depth + 1) {
            mark[x*2] = depth + 1;
            previous[x*2] = x;
            q.push({x * 2, depth + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < 210000; i++) mark[i] = 210000;
    bfs();
}