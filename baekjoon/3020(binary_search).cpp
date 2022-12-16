#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, H;
int minVal = 2000000000, minCnt;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> H;
    // 석순, 종유석
    vector<int> upward, downward, result;
    for(int i = 1; i <= N; i++) {
        int h; cin >> h;
        if(i % 2 != 0) { // 석순
            upward.push_back(h);
        }
        else { // 종유석
            downward.push_back(h);
        }
    }

    // 오름차순 정렬
    sort(upward.begin(), upward.end());
    sort(downward.begin(), downward.end());


    for(int i = 1; i <= H; i++) {
        // 석순
        int idx = lower_bound(upward.begin(), upward.end(), i) - upward.begin();
        int upperCnt = (int)upward.size() - idx;
        // 종유석
        idx = lower_bound(downward.begin(), downward.end(), H - i + 1) - downward.begin();
        int downwardCnt = (int)downward.size() - idx;

        minVal = min(minVal, upperCnt+downwardCnt);
        result.push_back(upperCnt + downwardCnt);
    }


    for(auto x : result) {
        if(x == minVal) minCnt++;
    }

    cout << minVal << ' ' << minCnt;
}