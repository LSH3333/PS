#include <iostream>
using namespace std;

#define MAX 10000

long long N;
int M;
long long attraction[MAX+1];

// time 시간 동안 몇명이 탈수있는지 계산
long long Count(long long time) {
    long long cnt = 0;
    for(int i = 0; i < M; i++) {
        cnt += time / attraction[i];
        if(time % attraction[i] != 0) cnt++;
    }
    return cnt;
}

// time 에 비어있는 놀이기구에 한명씩 탄다 
int CalAnswer(long long time, long long cnt) {
    for(int i = 0; i < M; i++) {
        if (time % attraction[i] == 0) {
            cnt++;
        }

        if(cnt == N) {
            return i;
        }
    }

    return -1;
}

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

    long long answerTime = 0, answerCnt = 0;
    // 최대 시간 = 20억 * 운행 시간 30
    long long left = 1, right = 2000000000*30L;
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = Count(mid);

        if(cnt >= N) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
            answerTime = mid;
            answerCnt = cnt;
        }
    }


    cout << CalAnswer(answerTime, answerCnt)+1;
}