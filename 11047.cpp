#include <iostream>
using namespace std;

int n, k;
int coin[10];

int main()
{
    cin >> n >> k;
    // 내림차순 정렬 되도록
    for(int i = n-1; i >= 0; i--)
    {
        cin >> coin[i];
    }

    int cnt = 0;

    while(k > 0)
    {
        // 갖고있는 동전들중 큰 액수 동전부터 탐색하면서 k보다 작은 동전이 나오면 k에서 뺀다
        // 동전이 내림차순으로 정렬되어있으므로 k보다 작은 액수중 가장 큰 동전이 무조건 선택된다
        for(int i = 0; i < n; i++)
        {
            if(coin[i] <= k)
            {
                cnt++;
                k -= coin[i];
                break;
            }
        }
    }

    cout << cnt;
}