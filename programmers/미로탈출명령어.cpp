#include <string>
#include <vector>
#include <iostream>

using namespace std;

// d l r u
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
char paths[] = {'d', 'l', 'r', 'u'};
int N, M, K;
int X, Y, R, C;
bool visited[2501][55][55];

bool dfs(int r, int c, int depth, string &path) {
    if(depth == K) {
        // ?? ??
        if(r == R && c == C) {
            return true;
        }
        return false;
    }

    bool res;
    for(int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if(nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
        if(visited[depth+1][nr][nc]) continue;

        visited[depth+1][nr][nc] = true;
        path.push_back(paths[i]);

        res = dfs(nr, nc, depth + 1, path);
        if(res) { return res; }

        path.pop_back();
    }

    return res;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    N = n, M = m, X = x, Y = y, R = r, C = c, K = k;

    string path;
    bool res = dfs(X, Y, 0, path);

    if(res) {
        answer = path;
    } else {
        answer = "impossible";
    }


    return answer;
}

int main() {
//    cout << solution(3, 4, 2, 3, 3, 1, 5);
    cout << solution(2, 2, 1, 1, 2, 2, 2);
//    solution(3, 3, 1, 2, 3, 3, 4);
}