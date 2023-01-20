#include <iostream>
#include <vector>
using namespace std;


#define INF 100000000

int N, M;
int cost[101][101];
int midNode[101][101]; // i에서 j로 가는데 거쳐가는 노드


void Floyd() {
    for(int k = 1; k <= N; k++) { // mid
        for(int i = 1; i <= N; i++) { // start
            for(int j = 1; j <= N; j++) { // end
                if(cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
                    midNode[i][j] = k;
                }
            }
        }
    }
}


void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(cost[i][j] == INF) cout << 0 << ' ';
            else cout << cost[i][j] << ' ';
        } cout << '\n';
    }
}

vector<int> answer;
void dfs(int i, int j) {
    int k = midNode[i][j];
    if(k == 0) {
        answer.push_back(i);
        answer.push_back(j);
        return;
    }

    dfs(i, k);
    answer.pop_back();
    dfs(k, j);
}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(cost[a][b] == 0) cost[a][b] = c;
        else cost[a][b] = min(cost[a][b], c);
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            if(cost[i][j] == 0) cost[i][j] = INF;
        }
    }


    Floyd();
    Print();

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(cost[i][j] == 0 || cost[i][j] == INF) {
                cout << 0;
            }
            else {
                dfs(i, j);
                cout << answer.size() << ' ';
                for(auto x : answer) cout << x << ' ';
                answer.clear();
            }
            cout << '\n';
        }
    }



}