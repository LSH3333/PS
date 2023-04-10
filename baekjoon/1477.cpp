#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, L;
vector<int> v;

int Cal(int mid) {
    int cnt = 0;
    for(int i = 1; i < v.size(); i++) {
        int length = v[i] - v[i-1];
        cnt += (length-1) / mid;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> L;
    for(int i = 1; i <= N; i++) {
        int n; cin >> n;
        v.push_back(n);
    }
    v.push_back(0);
    v.push_back(L);

    sort(v.begin(), v.end());

    int left = 1, right = 1000, answer = 1000;
    while(left <= right) {
        int mid = (left + right) / 2;

        int cnt = Cal(mid);
        if(cnt > M) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            answer = min(answer, mid);
        }

    }

    cout << answer;

}