#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    map<int,int> mp;
    int aCnt, bCnt;
    cin >> aCnt >> bCnt;
    for(int i = 0; i < aCnt; i++) {
        int n; cin >> n;
        mp[n]++;
    }
    for(int i = 0; i < bCnt; i++) {
        int n; cin >> n;
        mp[n]++;
    }

    int sub = 0;
    for (const auto &item: mp) {
        if(item.second >= 2) {
            sub++;
        }
    }

    int answer = (aCnt - sub) + (bCnt - sub);
    cout << answer;
}