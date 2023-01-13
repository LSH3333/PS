#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

// 구하는것 -> 몇번만에 정렬되는가
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        v[i] = {n, i};
    }
    sort(v.begin(), v.end());
    
    int answer = 0;
    for(int i = 0; i < N; i++) {
        answer = max(answer, v[i].second - i);
    }
    cout << answer+1;
}