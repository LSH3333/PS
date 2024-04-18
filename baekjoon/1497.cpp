#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
string arr[11];
bool visited[11];
bool possible;
int song_answer=-1, guitar_answer=-1;


void dfs(int idx, int depth, int goalDepth) {
    if(possible) return;
    if (depth == goalDepth) {
        string result(M, 'N');
        for(int i = 0; i < N; i++) {
            if(!visited[i]) continue;
            for(int j = 0; j < M; j++) {
                if (arr[i][j] == 'Y') {
                    result[j] = 'Y';
                }
            }
        }

        int cnt = 0;
        for (auto x: result) {
            if(x == 'Y') cnt++;
        }
        if (cnt > song_answer) {
            song_answer = cnt;
            guitar_answer = goalDepth;
        }
        return;
    }

    for(int i = idx; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, depth + 1, goalDepth);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string a,b; cin >> a >> b;
        arr[i] = b;
    }

    for(int i = 1; i <= N; i++) {
        possible = false;
        dfs(0, 0, i);
    }


    if(song_answer == 0) {
        cout << -1;
    } else {
        cout << guitar_answer;
    }
}