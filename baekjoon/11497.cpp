#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; // test case
    cin >> tc;

    while(tc--)
    {
        int arr[10001];
        int copy[10001];
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        // 오름차순 정렬
        sort(arr, arr+n);

        bool pushFront = true;
        int frontIdx = 0;
        int backIdx = n-1;
        for(int i = 0; i < n; i++)
        {
            if(pushFront)
            {
                copy[frontIdx] = arr[i];
                frontIdx++;
                pushFront = false;
            }
            else
            {
                copy[backIdx] = arr[i];
                backIdx--;
                pushFront = true;
            }
        }

        int ans = abs(copy[n-1] - copy[0]);
        for(int i = 0; i < n-1; i++)
        {
            ans = max(abs(copy[i]-copy[i+1]), ans);
        }
        cout << ans << '\n';
    }


}
