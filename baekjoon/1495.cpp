#include <iostream>
#include <vector>
using namespace std;

bool arr[1001][51];

int main()
{
    int N, S, M; cin >> N >> S >> M;
    arr[S][0] = true;
    for(int i = 1; i <= N; i++)
    {
        int vol; cin >> vol;
        bool found = false;
        for(int j = 0; j < 1001; j++)
        {
            if(arr[j][i-1])
            {
                if(j+vol <= M) { arr[j+vol][i] = true; found = true; }
                if(j-vol >= 0) { arr[j-vol][i] = true; found = true; }
            }
        }
        if(!found) { cout << -1; return 0; }
    }

    int answer = 0;
    for(int i = 0; i < 1001; i++)
    {
        if(arr[i][N]) answer = max(answer, i);
    }
    cout << answer;

}