#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, K;
pair<int,int> airfield[1010];
bool visited[1010];
int answer = 2000000000;

struct Data {
    int x,y;
    int depth;
};

int calRequireFuel(int x, int y, int nx, int ny) {
    double dist = sqrt(pow(x-nx, 2) + pow(y - ny, 2));
    int res = ceil((dist / 10));
    return res;
}

void Init() {
    for(int i = 0; i < 1010; i++) {
        visited[i] = false;
    }
}

bool bfs(int fuel) {
    Init();
    queue<Data> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        Data data = q.front();
        int x = data.x, y = data.y;
        int depth = data.depth;
        q.pop();


        if(x == 10000 && y == 10000) {
            return true;
        }
        if(depth > K) {
            continue;
        }

        for(int i = 0; i <= N; i++) {
            int nx = airfield[i].first, ny = airfield[i].second;
            if(visited[i]) continue;

            int reqFuel = calRequireFuel(x, y, nx, ny);

            if(reqFuel > fuel) continue;
            visited[i] = true;
            q.push({nx, ny, depth+1});
        }
    }

    return false;
}

//14142.1
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int x,y; cin >> x >> y;
        airfield[i] = {x, y};
    }

    airfield[N] = {10000, 10000};


    int l = 0, r = 2000;
    while(l <= r) {
        int mid = (l + r) / 2;

        bool res = bfs(mid);
        if(res) {
            r = mid - 1;
            answer = min(mid, answer);
        }
        else {
            l = mid + 1;
        }
    }

    cout << answer;
}