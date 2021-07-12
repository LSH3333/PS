#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 50

int N, M;
int ans;
int map[MAX][MAX];
bool mark[13];
vector<pair<int,int>> house, chicken;


// 집과 치킨집사이의 거리 구함 (멘헤튼 거리)
int CalculateDistance(pair<int,int> a, pair<int,int> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int Calculate() {
    // 도시의 치킨거리
    int chicken_distance = 0;
    for(int i = 0; i < house.size(); i++) {
        int min_distance = 99999999;
        for(int j = 0; j < chicken.size(); j++) {
            // 선택된 치킨집에 대해서만 계산
            if(mark[j]) {
                min_distance = min(min_distance, CalculateDistance(house[i], chicken[j]));
            }
        }
        // 현재 기준 집의 치킨거리를 더한다
        chicken_distance += min_distance;
    }
    return chicken_distance;
}

void dfs(int idx, int depth) {
    if(depth == M) {
        ans = min(ans, Calculate());
        return;
    }

    for(int i = idx; i < chicken.size(); i++) {
        if(mark[i]) continue;
        mark[i] = true;

        dfs(i, depth+1);

        mark[i] = false;
    }
}

int main() {
    // inputs
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int num;
            cin >> num;

            map[i][j] = num;

            if(num == 1) house.push_back({i,j});
            if(num == 2) chicken.push_back({i,j});
        }
    }

    ans = 99999999;
    dfs(0,0);

    cout << ans << '\n';
}

