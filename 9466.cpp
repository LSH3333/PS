#include <iostream>
using namespace std;
#define MAX 100001
#include <cstring>

int edge[MAX];
int cnt[MAX];
int group[MAX];
int res = 0;
int cnt_idx = 1, group_idx = 1;

void dfs(int n) {
    if(cnt[n] > 0) { // 이미 방문 정점
        if(group[n] == group_idx) { // 같은 그룹
            res += cnt_idx - cnt[n];
        }
        else { // 다른 그룹

        }
        return;
    }

    cnt[n] = cnt_idx; cnt_idx++;
    group[n] = group_idx;
    dfs(edge[n]);
}

void init() {
    memset(edge, 0, sizeof(edge));
    memset(cnt, 0, sizeof(cnt));
    memset(group, 0, sizeof(group));
    res = 0; cnt_idx = 1; group_idx = 1;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        for(int i = 1; i <= N; i++) cin >> edge[i];

        for(int i = 1; i <= N; i++) {
            if(cnt[i] == 0) {
                cnt_idx = 1;
                dfs(i);
                group_idx++;
            }
        }


        cout << N - res << endl;
        init();
    }


}