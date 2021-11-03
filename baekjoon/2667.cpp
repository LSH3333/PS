#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int apt[26][26];
int res[26][26];
int group_idx = 1, apt_num = 0;
int N;
int dx[4] = {0, 1, 0, -1}; // n e s w
int dy[4] = {-1, 0, 1, 0};
vector<int> v;

void dfs(int x, int y) {
    if(apt[x][y] == 0 || res[x][y] > 0) return; // 아파트가 없거나 or 이미 방문이면 리턴

    res[x][y] = group_idx;
    apt_num++;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i]; // 북동남서로 차례로 이동
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        dfs(nx, ny);

    }
}

int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d", &apt[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(apt[i][j] > 0 && res[i][j] == 0) { // 아파트가 있고 and 방문도 안함
                dfs(i,j);
                group_idx++;
                //cout << "aptnum = " << apt_num << endl;
                v.push_back(apt_num);
                apt_num = 0;
            }
        }
    }

    cout << group_idx-1 << endl;
    sort(v.begin(), v.end());
    for(int x : v) cout << x << endl;
}