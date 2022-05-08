#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<bool>> arr(1010, vector<bool>(1010, true));
    arr[0][0] = false;
    // (i,j)에 의해 가려지는 점들 false로 체크 
    for(int i = 0; i <= 1000; i++)
    {
        for(int j = 0; j <= 1000; j++)
        {
            if(i == 0 && j == 0) continue;
            if(!arr[i][j]) continue;

            int a = i, b = j;
            while(true)
            {
                a += i; b += j;
                if(a > 1000 || b > 1000) break;
                arr[a][b] = false;
            }
        }
    }

    int answer[1010];
    int cnt = 0;
    for(int i = 0; i <= 1000; i++)
    {
        for(int a = 0; a < i; a++)
        {
            cnt += arr[i][a];
            cnt += arr[a][i];
        }
        cnt += arr[i][i];

        answer[i] = cnt;
    }

    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        cout << answer[N] << '\n';
    }

}