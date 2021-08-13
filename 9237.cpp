#include <iostream>
#include <algorithm>
using namespace std;

int n;
int tree[100010];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> tree[i];
    }

    // 내림차순 정렬
    sort(tree+1, tree+n+1, greater<>());

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        // tree[i] 묘목이 다 자라는 날
        int grown = i + tree[i] + 1;
        ans = max(ans, grown);
    }
    cout << ans;
}