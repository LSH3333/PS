#include <iostream>
using namespace std;

int N, L, R, X;
int problems[20];
bool visited[20];
int answer;

bool Check() {
    int minVal = 2000000, maxVal = 0, sum = 0;
    for(int i = 0; i < N; i++) {
        if(!visited[i]) continue;
        minVal = min(minVal, problems[i]);
        maxVal = max(maxVal, problems[i]);
        sum += problems[i];
    }

    if(maxVal - minVal < X) return false;
    if(sum < L || sum > R) return false;
    return true;
}

void dfs(int idx, int depth, int goalDepth) {
    if (depth == goalDepth) {
        if(Check()) answer++;
        return;
    }

    for(int i = idx; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i + 1, depth + 1, goalDepth);
        visited[i] = false;
    }
}

int main() {
    cin >> N >> L >> R >> X;
    for(int i = 0; i < N; i++) {
        cin >> problems[i];
    }

    for(int i = 2; i <= N; i++) {
        dfs(0, 0, i);
    }

    cout << answer;
}