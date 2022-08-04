#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int d[10010][21];



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        memset(d, 0, sizeof(d));

        int N; cin >> N;
        vector<int> coins(N);
        for(int i = 0; i < N; i++)
        {
            cin >> coins[i];
            d[coins[i]][i] = 1;
        }
        int goal; cin >> goal;


        for(int i = 2; i <= goal; i++)
        {
            for(int j = 0; j < N; j++)
            {
                int coin = coins[j];
                if(i-coin < 1) continue;
                for(int k = j; k < N; k++)
                {
                    d[i][j] += d[i-coin][k];
                }
            }
        }
        
        int answer = 0;
        for(int j = 0; j < N; j++) answer += d[goal][j];
        cout << answer << '\n';
    }

}