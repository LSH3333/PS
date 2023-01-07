#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;
int goalBegin, goalEnd;
int monthday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int DateToDay(int month, int day) {
    int res = 0;
    for(int i = 1; i < month; i++) res += monthday[i];
    res += day;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v[i] = {DateToDay(a, b), DateToDay(c, d) };
    }

    sort(v.begin(), v.end());
    goalBegin = DateToDay(3,1);
    goalEnd = DateToDay(11,30);

    // 3.1 이전 시작 꽃 중 가장 긴 꽃 찾음
    int right=-1;
    int idx;
    for(idx = 0; idx < N; idx++) {
        if(v[idx].first > goalBegin) break;
        if(v[idx].second > right) {
            right = v[idx].second;
        }
    }
    answer = 1;

    //
    while(right <= goalEnd) {
        int maxVal = 0, maxIdx = 0;
        for(; idx < N; idx++) {
            if(v[idx].first > right) break;
            if(v[idx].second > maxVal) {
                maxVal = v[idx].second;
                maxIdx = idx;
            }
        }
        if(maxVal == 0) break;

        answer++;
        right = v[maxIdx].second;
    }

    if(right <= goalEnd) cout << 0;
    else cout << answer;

}