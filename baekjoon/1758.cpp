#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100010

int n;
int ppl[MAX];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ppl[i];

    // 내림차순 정렬
    sort(ppl, ppl+n, greater<>());

    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        int tip = ppl[i] - i;
        if(tip <= 0) continue;

        ans += tip;
    }
    cout << ans;
}