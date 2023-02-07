#include <iostream>
using namespace std;

int N, M;
int attraction[10010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> attraction[i];
    }

    if(N <= M) {
        cout << N;
        return 0;
    }

    long long result = 0; // 마지막 아이가 타는 시간
    long long left = 0, right = 2000000000L * 30L;
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long sum = M; // 최초에 놀이기구는 모두 비어있으므로 M명 모두 탈수 있음
        for(int i = 0; i < M; i++) {
            sum += mid / attraction[i];
        }

        if(sum >= N) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }


    // result 분에 마지막 아이가 탄다
    // result-1 분에 몇명이 타는가?
    long long beforeCnt = M; // result-1 분에 타는 아이의 수
    for(int i = 0; i < M; i++) {
        beforeCnt += (result - 1) / attraction[i];
    }

    // result 분에 새롭게 타는 아이들 계산
    long long answer = 0;
    for(int i = 0; i < M; i++) {
        if(result % attraction[i]== 0) {
            beforeCnt++;
            if(beforeCnt == N) {
                answer = i + 1;
                break;
            }
        }
    }

    cout << answer;

}