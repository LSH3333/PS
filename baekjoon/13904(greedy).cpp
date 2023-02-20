#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int mark[1010];

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++) {
        int d, w; cin >> d >> w;
        v[i] = {d, w};
    }

    // 점수 기준 내림 차순
    sort(v.begin(), v.end(), cmp);

    for(auto x : v) {
        int d = x.first, w = x.second;

        for(int i = d; i > 0; i--) {
            if(mark[i] == 0) {
                mark[i] = w;
                break;
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= 1000; i++) {
        answer += mark[i];
    }
    cout << answer;
}