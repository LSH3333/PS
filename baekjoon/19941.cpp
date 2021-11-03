#include <iostream>
using namespace std;

int n,k;
char loc[20010];
bool ate[20010];
int ans = 0;

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> loc[i];


    // 도달할수 있는 가장 먼 좌측편 부터 햄버거 먹음
    for(int i = 0; i < n; i++)
    {
        if(loc[i] == 'P')
        {
            bool found = false;
            // left side
            for(int j = k; j >= 1; j--)
            {
                int left = i-j;
                if(left < 0) continue;
                if(loc[left] == 'H' && !ate[left])
                {
                    ate[left] = true;
                    ans++;
                    found = true;
                    break;
                }
            }
            // 좌측에서 이미 먹었으므로 우측 탐색하지 않음
            if(found) continue;
            // right side
            for(int j = 1; j <= k; j++)
            {
                int right = i+j;
                if(right >= n) continue;
                if(loc[right] == 'H' && !ate[right])
                {
                    ate[right] = true;
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans;
}