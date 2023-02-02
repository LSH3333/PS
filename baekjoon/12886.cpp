#include <iostream>
#include <algorithm>
using namespace std;

bool visited[5000][5000];

void dfs(int A, int B, int C) {
    if(A == B && B == C) {
        cout << 1;
        exit(0);
    }

    if(A != B) {
        int X = min(A,B);
        int Y = max(A,B);
        if (!visited[X][Y] && !visited[Y][X]) {
            visited[X][Y] = true;
            visited[Y][X] = true;
            dfs(X*2, Y-X, C);
        }
    }
    if(A != C) {
        int X = min(A, C);
        int Y = max (A, C);
        if (!visited[X][Y] && !visited[Y][X]) {
            visited[X][Y] = true;
            visited[Y][X] = true;
            dfs(X * 2, B, Y - X);
        }
    }
    if(B != C) {
        int X = min(B, C);
        int Y = max(B, C);
        if (!visited[X][Y] && !visited[Y][X]) {
            visited[X][Y] = true;
            visited[Y][X] = true;
            dfs(A, X * 2, Y - X);
        }
    }
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    dfs(A, B, C);
    cout << 0;

}