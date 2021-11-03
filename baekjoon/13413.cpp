#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        string initial, goal;
        cin >> n >> initial >> goal;

        int bw = 0, wb = 0, none = 0;
        for(int i = 0; i < n; i++)
        {
            if(initial[i] == 'B' && goal[i] == 'W')
                bw++;

            else if(initial[i] == 'W' && goal[i] == 'B')
                wb++;
            else if(initial[i] != goal[i])
                none++;
        }

        int minCnt = min(bw,wb);
        int maxCnt = max(bw,wb);

        int swapCnt = minCnt;
        int left = maxCnt - swapCnt;
        int ans = swapCnt + left + none;

        cout << ans << '\n';
    }



}
