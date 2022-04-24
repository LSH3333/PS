#include <iostream>
#include <algorithm>
using namespace std;

int a[1010];

int main()
{
    int N, L;
    cin >> N >> L;
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);

    // 테이프 끝나는 지점
    double end = a[0] - 0.5 + L;
    int cnt = 1; // 필요한 테이프 갯수
    for(int i = 1; i < N; i++)
    {
        if(a[i]+0.5 <= end) continue;
        else
        {
            cnt++;
            end = a[i] - 0.5 + L;
        }
    }
    cout << cnt;
}