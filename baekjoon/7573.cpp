#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,L,M;

int GetNumCatchFishes(int rLen, int cLen, const vector<pair<int,int>> &fishes) {
    int maxCnt = 0;

    for(int i = 0; i < fishes.size(); i++) {
        int cnt = 1;
        for(int j = 0; j < fishes.size(); j++) {
            if(i == j) continue;
            if (fishes[j].first - fishes[i].first <= rLen &&
                fishes[j].first - fishes[i].first >= 0 &&
                fishes[j].second - fishes[i].second <= cLen &&
                fishes[j].second - fishes[i].second >= 0) {
                cnt++;
            }
        }
        maxCnt = max(maxCnt, cnt);
    }

    for(int i = 0; i < fishes.size(); i++) {
        int cnt = 1;
        for(int j = 0; j < fishes.size(); j++) {
            if(i == j) continue;
            if (fishes[j].first - fishes[i].first >= 0 &&
                fishes[j].first - fishes[i].first <= rLen &&
                fishes[j].second - fishes[i].second <= 0 &&
                abs(fishes[j].second - fishes[i].second) <= cLen) {
                cnt++;
            }
        }
        maxCnt = max(maxCnt, cnt);
    }

    return maxCnt;
}

int main() {
    vector<pair<int,int>> fishes;
    cin >> N >> L >> M;
    for(int i = 0; i < M; i++) {
        int r,c; cin >> r >> c;
        fishes.push_back({r, c});
    }
//    sort(fishes.begin(), fishes.end());

    int answer = 0;
    // 5000 * 100 * 100
    for(int rLen = 1; rLen < L/2; rLen++) {
        int cnt = GetNumCatchFishes(rLen, L/2-rLen, fishes);
        answer = max(answer, cnt);
    }

    cout << answer;
}