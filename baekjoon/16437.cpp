#include <iostream>
#include <vector>
using namespace std;

#define SHEEP 0
#define WOLF 1

int N;
// sheep or wolf, sheepCnt, wolfCnt
long long island[130000][3];
int parent[130000];
vector<int> child[130000];
long long answer;
int nextWolfNode[130000];

void FindNextWolf(int cur, int wolfNode) {
    nextWolfNode[cur] = wolfNode;
    for (auto next: child[cur]) {
        if(island[next][0] == SHEEP) {
            FindNextWolf(next, wolfNode);
        }
        else {
            FindNextWolf(next, next);
        }
    }
}


void dfs(int cur) {
    int next = parent[cur];
    if(island[cur][0] == SHEEP) {
        parent[cur] = nextWolfNode[cur];
    }

    if(next == 1) {
        answer += island[cur][1];
        island[cur][1] = 0;
        return;
    }
        // 다음 섬이 늑대섬
    else if (island[next][0] == WOLF) {
        // 현재 양의 수가 다음 늑대섬의 늑대수보다 많은 경우
        if(island[cur][1] > island[next][2]) {
            island[next][1] += island[cur][1] - island[next][2];
            island[cur][1] = 0;
            island[next][2] = 0;
        }
            // 현재 양의 수가 다음 늑대섬의 늑대수 보다 작거나 같은 경우
        else {
            island[next][2] -= island[cur][1];
            island[cur][1] = 0;
        }
    }
        // 다음 섬이 양 섬
    else {
        island[next][1] += island[cur][1];
        island[cur][1] = 0;
    }

    dfs(next);
}

void FindLeaf(int cur) {
    if(child[cur].empty()) {
        dfs(cur);
        return;
    }

    for (auto childNode: child[cur]) {
        FindLeaf(childNode);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    island[1][0] = WOLF;
    for(int i = 2; i <= N; i++) {
        char t; int a, p;
        cin >> t >> a >> p;

        if(t == 'S') {
            island[i][0] = SHEEP;
            island[i][1] = a;
        }
        else {
            island[i][0] = WOLF;
            island[i][2] = a;
        }
        parent[i] = p;
        child[p].push_back(i);
    }


    FindNextWolf(1, 1);
    FindLeaf(1);

    cout << answer;

}