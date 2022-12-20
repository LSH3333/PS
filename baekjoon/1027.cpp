#include <iostream>
using namespace std;

int N;
int answer;
double building[55];

// 두 점의 좌표로 직선의 방정식 구함.
// x값에 따른 y좌표 리턴함
double Cal(double x1, double y1, double x2, double y2, double x) {
    double m = (y2 - y1) / (x2 - x1);
    return m*x - m*x1 + y1;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> building[i];
    }

    // 기준 빌딩
    for(int i = 1; i <= N; i++) {
        int cnt = 0;
        // 다른 빌딩
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;

            bool can = true; // i와 j 사이 빌딩이 k 빌딩에 의해 가려진다면 false
            // 사이 빌딩
            for(int k = min(i,j)+1; k < max(i,j); k++) {
                double yVal = Cal(i, building[i], j, building[j], k);
                if(yVal <= building[k]) {
                    can = false; break;
                }
            }

            if(can) cnt++;
        }
        answer = max(answer, cnt);
    }
    cout << answer;
}