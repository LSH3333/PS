#include <iostream>
#include <vector>
using namespace std;

long long len[10001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K, N; cin >> K >> N;
    long long left = 0, right = 0;
    for(int i = 0; i < K; i++) { cin >> len[i]; right += len[i]; }

    long long answer = 0;
    while(left <= right)
    {
        long long mid = (left + right) / 2;
        if(mid == 0) mid++;
        // 만들수 있는 랜선 갯수
        long long cnt = 0;
        for(int i = 0; i < K; i++) cnt += (len[i] / mid);
//        cout << left << ' ' << mid << ' ' << right << endl;
//        cout << "cnt: " << cnt << endl << endl;
        // 만들수 있는 랜선 갯수가 필요한 랜선 갯수보다 적음
        if(cnt < N)
        {
            right = mid - 1;
        }
        else // N개 이상 민들수 있음
        {
            left = mid + 1;
            answer = max(mid, answer);
        }
    }
    cout << answer;
}