#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int FindBook(int a, int b, vector<bool> &mark) {
    int i = a;
    while(i <= b) {
        if(!mark[i]) return i;
        i++;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N, M, answer=0;
        cin >> N >> M;
        vector<pair<int,int>> v(M);
        vector<bool> mark(N, false);
        for(int i = 0; i < M; i++) {
            int a, b; cin >> a >> b;
            v[i] = {a, b};
        }

        sort(v.begin(), v.end(), cmp);

        for(int i = 0; i < M; i++) {
            int a = v[i].first, b = v[i].second;
            int res = FindBook(a, b, mark);
            if(res != -1) {
                mark[res] = true;
                answer++;
            }
        }

        cout << answer << '\n';
    }


}