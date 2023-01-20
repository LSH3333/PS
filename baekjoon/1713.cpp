#include <iostream>
using namespace std;

int N, M;
int votes[110];
int date[110];

void DeleteMinVote() {
    int minVote = 100000, minVoteIdx = 0, minDate = 100000;

    for(int i = 1; i <= 100; i++) {
        if(votes[i] == 0) continue;
        if(votes[i] < minVote) {
            minVote = votes[i];
            minDate = date[i];
            minVoteIdx = i;
        }
        if(votes[i] == minVote && date[i] < minDate) {
            minVote = votes[i];
            minDate = date[i];
            minVoteIdx = i;
        }
    }

    votes[minVoteIdx] = 0;
    date[minVoteIdx] = 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    int cnt = 0;
    for(int idx = 0; idx < M; idx++) {
        int n; cin >> n;

        // 이미 사진틀에 있는 학생이 추천된 경우
        if(votes[n] > 0) {
            votes[n]++;
        }
        else {
            // 비어 있는 사진틀 있는 경우
            if(cnt < N) {
                votes[n]++;
                date[n] = idx;
                cnt++;
            }
            // 없는 경우
            else {
                DeleteMinVote();
                votes[n]++;
                date[n] = idx;
            }
        }
    }

    for(int i = 1; i <= 100; i++) {
        if(votes[i] > 0) cout << i << ' ';
    }
}