#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int answer;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<pair<int,int>> v;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());

    int begin = v.front().first, end = v.front().second;
    for(int i = 1; i < v.size(); i++) {
        int x = v[i].first, y = v[i].second;
        if(x <= end) {
            end = max(y, end);
        }
        else {
            answer += (end - begin);
            begin = x;
            end = y;
        }
    }
    answer += (end - begin);
    cout << answer;
}
