#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        string n,m;
        cin >> n >> m;

        int one= 0,zero = 0;
        for(int i = 0; i < n.size(); i++)
        {
            if(n[i] == m[i]) continue;
            if(n[i] == '0') zero++;
            else
                one++;
        }

        int ans = 0;
        int many = max(one,zero);
        int less = min(one,zero);

        ans += less;
        ans += many-less;

        cout << ans << '\n';
    }
}