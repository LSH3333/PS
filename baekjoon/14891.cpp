#include <iostream>
#include <vector>
using namespace std;

int gear[5][9];
vector<pair<int,int>> turnGear;

void UpWard(int cur, int dir)
{
    // 다음 톱니로
    if(cur+1 <= 4 && gear[cur+1][7] != gear[cur][3])
    {
        turnGear.push_back({cur+1, dir*-1});
        UpWard(cur+1, dir*-1);
    }
}

void DownWard(int cur, int dir)
{
    // 이전 톱니로
    if(cur-1 >= 1 && gear[cur-1][3] != gear[cur][7])
    {
        turnGear.push_back({cur-1, dir*-1});
        DownWard(cur-1, dir*-1);
    }
}

void TurnGear()
{
    for(auto x : turnGear)
    {
        int n = x.first;
        // clock wise
        if(x.second == 1)
        {
            int tmp = gear[n][8];
            for(int i = 8; i >= 2; i--) gear[n][i] = gear[n][i-1];
            gear[n][1] = tmp;
        }
        else // counter clock wise
        {
            int tmp = gear[n][1];
            for(int i = 1; i <= 7; i++) gear[n][i] = gear[n][i+1];
            gear[n][8] = tmp;
        }
    }
}

int main()
{
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            int num; scanf("%1d", &num);
            gear[i][j] = num;
        }
    }

    int k; cin >> k;
    while(k--)
    {
        int n, dir; cin >> n >> dir;
        turnGear.push_back({n, dir});
        UpWard(n, dir);
        DownWard(n, dir);
        TurnGear();
        turnGear.clear();
    }

    int a = gear[1][1] == 1 ? 1 : 0;
    int b = gear[2][1] == 1 ? 2 : 0;
    int c = gear[3][1] == 1 ? 4 : 0;
    int d = gear[4][1] == 1 ? 8 : 0;
    cout << a+b+c+d;
}