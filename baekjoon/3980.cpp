#include <iostream>
using namespace std;

int board[11][11];
int answer;
bool visited[11];

void dfs(int depth, int sum) {
    if(depth == 11) {
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < 11; i++) {
        if(board[depth][i] == 0 || visited[i]) continue;
        visited[i] = true;
        dfs(depth + 1, sum + board[depth][i]);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        for(int i = 0; i < 11; i++) {
            for(int j = 0; j < 11; j++) {
                cin >> board[i][j];
            }
        }

        dfs(0, 0);

        cout << answer << '\n';

        answer = 0;
    }


}