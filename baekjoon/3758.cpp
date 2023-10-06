#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000

int N, K, T, M;
// [???][????]
int board[MAX][101];
// ?? ?? ??
int submits[MAX];
int lastSubmits[MAX];

struct Team {
    int id, score, submit, lastSubmit;
};

bool cmp(const Team &a, const Team &b) {
    if(a.score == b.score) {
        if(a.submit == b.submit) {
            return a.lastSubmit < b.lastSubmit;
        }
        return a.submit < b.submit;
    }
    return a.score > b.score;
}

void Init() {
    for(int i = 1; i <= N; i++) {
        submits[i] = 0;
        lastSubmits[i] = 0;
        for(int j = 1; j <= K; j++) {
            board[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;
    while(tc--) {
        cin >> N >> K >> T >> M;
        Init();

        for(int _i = 0; _i < M; _i++){
            int id, prob, score; cin >> id >> prob >> score;
            board[id][prob] = max(board[id][prob], score);
            submits[id]++;
            lastSubmits[id] = _i;
        }

        // ?? id, ?? ?? ??, ?? ??, ??? ?? ??
        vector<Team> v;
        for(int id = 1; id <= N; id++) {
            int score = 0;
            for(int prob = 1; prob <= K; prob++) {
                score += board[id][prob];
            }
            v.push_back({id, score, submits[id], lastSubmits[id]});
        }

        sort(v.begin(), v.end(), cmp);

        for(int i = 0; i < v.size(); i++) {
            if(v[i].id == T) {
                cout << i+1 << '\n';
                break;
            }
        }
    }


}