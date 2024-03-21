#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M, K;
vector<string> words;
unordered_map<string, int> um;
char board[11][11];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c, string &str) {
    // ?? ???? ???
    if (um.find(str) != um.end()) {
        um[str]++;
    }
    if(str.size() > 5) {
        return;
    }

    for(int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];

        if(nr < 0) nr = N - 1;
        if(nr >= N) nr = 0;
        if(nc < 0) nc = M - 1;
        if(nc >= M) nc = 0;

        string nextStr = str;
        nextStr.push_back(board[nr][nc]);

        dfs(nr, nc, nextStr);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < K; i++) {
        string str; cin >> str;
        words.push_back(str);
        um[str] = 0;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            string str;
            str.push_back(board[i][j]);
            dfs(i, j, str);
        }
    }

    for(auto x : words) {
        cout << um[x] << '\n';
    }
}