#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int answer = 100000000;

void permutation(int depth, string &res, const vector<int> &buttons) {
    if(depth == 7) {
        return;
    }

    answer = min(answer, abs(N - stoi(res)) + depth);

    for(int i = 0; i < buttons.size(); i++) {
        res += to_string(buttons[i]);
        if(stoi(res) > 1000000) continue;
        permutation(depth + 1, res, buttons);
        res.pop_back();
    }
}

void dfs(int depth, int num, const vector<int> &buttons) {
    if(depth == 7) return;

    if(depth > 0) {
        answer = min(answer, abs(N - num) + depth);
    }

    for(auto button : buttons) {
        int next;
        if(depth == 0) {
            next = button;
        }
        else {
            next = num * 10 + button;
        }
        dfs(depth+1, next, buttons);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    vector<int> buttons = {0,1,2,3,4,5,6,7,8,9};
    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        buttons.erase(find(buttons.begin(), buttons.end(), n));
    }

    answer = min(answer, abs(100-N));

    dfs(0, 0, buttons);


    cout << answer;

}