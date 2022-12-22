#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


void MakeSumArray(const vector<int> &arr, vector<int> &arrSum, int cnt) {
    int sum = 0;
    for(int i = 0; i < cnt; i++) sum += arr[i];
    arrSum.push_back(sum);

    for(int i = cnt; i < arr.size(); i++) {
        sum += arr[i];
        sum -= arr[i-cnt];
        arrSum.push_back(sum);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long T, N, M;
    long long answer = 0;
    vector<int> A, B;
    vector<int> ASum, BSum;

    cin >> T >> N;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        A.push_back(n);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        B.push_back(n);
    }


    // ASum, BSum 벡터 완성시킴
    for(int i = 1; i <= N; i++) {
        MakeSumArray(A, ASum, i);
    }
    for(int i = 1; i <= M; i++) {
        MakeSumArray(B, BSum, i);
    }

    //
    sort(ASum.begin(), ASum.end());
    sort(BSum.begin(), BSum.end());

    for(long long i = 0; i < ASum.size();) {
        // A
        long long AVal = ASum[i];
        long long begin = lower_bound(ASum.begin(), ASum.end(), AVal) - ASum.begin();
        long long end = upper_bound(ASum.begin(), ASum.end(), AVal) - ASum.begin();
        long long ACnt = end - begin;

        // B
        long long findVal = T - AVal;
        begin = lower_bound(BSum.begin(), BSum.end(), findVal) - BSum.begin();
        end = upper_bound(BSum.begin(), BSum.end(), findVal) - BSum.begin();
        long long BCnt = end - begin;
        
        answer += (ACnt * BCnt);
        i += ACnt;
    }

    cout << answer;

}