#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000010
int N, M;
vector<int> buttons;
int answer;

void dfs(int num, int depth) {
    if(depth == 7) {
        return;
    }

    answer = min(answer, abs(N - num)+depth);

    for(auto btn : buttons) {
        int nextNum = (num * 10) + btn;
        if(nextNum >= MAX) continue;
        dfs(nextNum, depth+1);
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    vector<bool> tmp(10, true);
    for (int i = 0; i < M; i++) {
        int b; cin >> b;
        tmp[b] = false;
    }
    for (int i = 0; i <= 9; i++) {
        if(tmp[i]) buttons.push_back(i);
    }

    answer = abs(N - 100);
    for(auto btn : buttons) {
        dfs(btn, 1);
    }
    cout << answer;
}