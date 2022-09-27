#include <iostream>
using namespace std;

bool d[1001][1001];

int main()
{
    int N; cin >> N;
    int answer = 0;
    d[1][N] = true;
    for(int i = 1; i <= N; i++)
    {
        if(d[i][1])
        {
            answer = i;
            break;
        }

        for(int j = 1; j <= N; j++)
        {
            if(d[i][j])
            {
                d[i+1][j-1] = true;
                d[i+1][j-3] = true;
            }
        }
    }

    if(answer % 2 == 0) cout << "SK";
    else cout << "CY";
}