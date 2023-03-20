#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> arr(N);
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        arr[i] = {n, i};
    }

    sort(arr.begin(), arr.end());
    
    // 버블 정렬 과정에서 왼쪽으로 이동한 휫수 계산
    int answer = 0;
    for(int i = 0; i < N; i++) {
        answer = max(answer, arr[i].second - i + 1);
    }
    
    cout << answer;
}