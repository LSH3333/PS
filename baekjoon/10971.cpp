#include <iostream>
#include <algorithm>
using namespace std;
#define INF 2147483647

int main() {
    int n;
    int map[10][10];

    cin >> n;
    for(int i = 0; i < n; i++) { // 지도 작성
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int idx[20]; // permutation 위한 인덱스 0, 1, 2, 3
    for(int i = 0; i < n; i++) {
        idx[i] = i;
    }


    int res = INF;
    bool trig = false; bool stuck = false;
    do {
        int sum = 0; int cnt = 0;
        // 0->1, 1->2, 2->3 비용 합산
        // 그후 0->1, 1->3, 3->2 ...
        for(int i = 0; i < n-1; i++) {
            if(map[idx[i]][idx[i+1]] == 0) continue; // 길이 막혔으면
            sum += map[idx[i]][idx[i+1]]; cnt++;
        }
        // 출발지점으로 돌아가는 길이 있다면, 비용 합산
        if(map[idx[n-1]][idx[0]] != 0) {
            sum += map[idx[n-1]][idx[0]];
            cnt++;
        }

        if(cnt == n) res = (res > sum) ? sum : res;

        //cout << res << endl;
    } while(next_permutation(idx, idx+n));

    cout << res;
}