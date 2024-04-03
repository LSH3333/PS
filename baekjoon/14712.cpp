#include <iostream>
using namespace std;

int N, M;
bool visited[30][30];
int answer;

void dfs(int idx) {
    if(idx == N*M) {
        answer++;
        return;
    }

    int r = idx / M;
    int c = idx % M;

    // [r][c] ??
    if ((r==0 || c==0) ||
        (r - 1 >= 0 && c - 1 >= 0 && (!visited[r - 1][c - 1] || !visited[r - 1][c] || !visited[r][c - 1]))) {
        visited[r][c] = true;
        dfs(idx+1);
        visited[r][c] = false;
    }

    // [r][c] ?? x
    dfs(idx+1);
}

int main() {
    cin >> N >> M;
    dfs(0);
    cout << answer;
}