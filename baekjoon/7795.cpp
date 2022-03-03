#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        int ans = 0;
        vector<int> A(n);
        vector<int> B(m);
        for(int i = 0; i < n; i++) { int num; cin >> num; A[i] = num * -1; }
        for(int i = 0; i < m; i++) { int num; cin >> num; B[i] = num * -1; }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        auto aptr = A.begin();
        auto bptr = B.begin();
        while(aptr != A.end() && bptr != B.end())
        {
            bptr = upper_bound(bptr, B.end(), *aptr);
            ans += m - (bptr - B.begin());
            aptr++;
        }

        cout << ans << '\n';
    }

}