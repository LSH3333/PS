#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
int rope[100001];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> rope[i];

    sort(rope, rope+n);

    for(int i = 0; i < n; i++)
    {
        int res = rope[i] * (n-i);
        ans = max(ans, res);
    }
    cout << ans;

}