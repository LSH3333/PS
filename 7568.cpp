#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<pair<int,int>> v;
    vector<int> ans;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    for(int i = 0; i < v.size(); i++) {
        int bigger = 0; // i보다 덩치가 큰 사람수
        for(int j = 0; j < v.size(); j++) {
            if(j == i) continue; // 나자신과는 비교할 필요없다
            // 비교되는 j가 현재기준인 i보다 덩치가 크다면
            if(v[i].first < v[j].first && v[i].second < v[j].second) {
                bigger++; // 덩치큰 사람수 증가
            }
        }
        // 나보다 덩치큰 사람이 bigger명 있으므로 나는 bigger+1 번째
        ans.push_back(bigger+1);
    }

    for(int x : ans) cout << x << ' ';

}