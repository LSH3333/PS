#include <iostream>
using namespace std;

int N, M;
int d[1010][1010];
int ans;

int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < M; j++)
        {
            if(str[j] == '1')
            {
                d[i][j+1] = 1;
                ans = 1;
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(d[i][j] == 0) continue;
            d[i][j] = min(d[i-1][j-1], min(d[i-1][j], d[i][j-1]))+1;
            ans = max(ans, d[i][j]);
        }
    }


    cout << ans * ans;
}