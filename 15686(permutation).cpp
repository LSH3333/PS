// boj 15686
// permutation을 이용해 푼 버전

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
//int idx[13];
vector<int> idx;
int ans = 99999999;

vector<pair<int,int>> chicken, house;

int CalculateDistance(pair<int,int> a, pair<int,int> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int Calculate() {
    int chicken_distance = 0;

    for(int i = 0; i < house.size(); i++) {
        int dist = 99999999;
        for(int j = 0; j < chicken.size(); j++) {
            // 선택된 치킨집에 대해서
            if(idx[j] == 0) continue;
            dist = min(dist, CalculateDistance(house[i], chicken[j]));
        }
        chicken_distance += dist;
    }

    return chicken_distance;
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int num;
            cin >> num;

            if(num == 1) house.push_back({i,j});
            if(num == 2) chicken.push_back({i,j});
        }
    }

    // 치킨집이 총 5개고 M이 2라면
    // 1 1 0 0 0
    for(int i = 0; i < chicken.size(); i++) {
        if(i < M)
            idx.push_back(1);
        else
            idx.push_back(0);
    }



    // idx를 permutation 돌리면서 모든 조합 찾아냄
    // 즉 치킨집을 m개 선택
    do {
        ans = min(ans, Calculate());

    } while(prev_permutation(idx.begin(), idx.end()));

    cout << ans;

}