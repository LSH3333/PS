#include <iostream>
#include <vector>
using namespace std;

#define MAX 130000
#define SHEEP 0
#define WOLF 1

int N;
vector<int> child[MAX];
int island[MAX][2]; // 0:sheep or wolf, 1:cnt

long long dfs(int cur) {
    // leaf node
    if (child[cur].empty()) {
        if(island[cur][0] == SHEEP) return island[cur][1];
        else return 0;
    }

    long long res = 0;
    for (auto next: child[cur]) {
        res += dfs(next);
    }

    // 현재 섬 계산
    if(island[cur][0] == WOLF) {
        res -= island[cur][1];
    }
    else {
        res += island[cur][1];
    }
    if(res < 0) res = 0;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 2; i <= N; i++) {
        char t; int a, p;
        cin >> t >> a >> p;
        t == 'S' ? island[i][0] = SHEEP : island[i][0] = WOLF;
        island[i][1] = a;
        child[p].push_back(i);
    }

    cout << dfs(1);
}