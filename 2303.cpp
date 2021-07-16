#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cards[1001][5];
int mark[5] = {1, 1, 1, 0, 0};
// 각 사람들이 낼수 있는 최대값이 저장됨
int maxs[1001];


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> cards[i][j];
        }
    }


    do {

        for(int a = 0; a < n; a++)
        {
            int sum[1001] = {0,};

            for(int i = 0; i < 5; i++)
            {
                if(mark[i] == 1)
                    sum[a] += cards[a][i];
            }

            maxs[a] = max(maxs[a], sum[a] % 10);

        }

    } while(prev_permutation(mark, mark+5));


    int winner = 0;
    int highest = maxs[0];
    for(int i = 1; i < n; i++)
    {
        if(maxs[i] >= highest)
        {
            winner = i;
            highest = maxs[i];
        }
    }

    cout << winner+1;
}