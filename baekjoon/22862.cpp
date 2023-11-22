#include <iostream>
using namespace std;

int N, K, answer;
int S[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int l=0,r=0,oddCnt=0;
    while(r < N) {
        if(oddCnt <= K) {
            if(S[r] % 2 != 0) {
                oddCnt++;
                r++;
            } else {
                r++;
                answer = max(answer, r - l - oddCnt);
            }
        }
        else {
            if(S[l] % 2 != 0) {
                oddCnt--;
            }
            l++;
        }
    }

    cout << answer;
}