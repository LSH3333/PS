#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int answer;
bool visited[110];

int cnt = 0;
void CheckRelation(int n, vector<int> *edge) {
    for (auto next: edge[n]) {
        if(visited[next]) continue;
        cnt++;
        visited[next] = true;
        CheckRelation(next, edge);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<int> heavier[110];
    vector<int> lighter[110];

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        lighter[a].push_back(b);
        heavier[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        int maxVal = 0;

        cnt = 0;
        memset(visited, false, sizeof(visited));
        CheckRelation(i, heavier);
        maxVal = max(maxVal, cnt);

        cnt = 0;
        memset(visited, false, sizeof(visited));
        CheckRelation(i, lighter);
        maxVal = max(maxVal, cnt);

        if(maxVal > N/2) {
            answer++;
        }
    }

    cout << answer;
}