#include <iostream>
#include <vector>
using namespace std;

int T;

void Print(const vector<vector<char>> &gears)
{
    for(int i = 1; i <= T; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cout << gears[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

// gear 시계 방향 회전
void ClockWise(vector<char> &gear)
{
    char last = gear.back();
    for(int i = 7; i > 0; i--) gear[i] = gear[i-1];
    gear[0] = last;
}
// gear 반시계 방향 회전
void AntiClockWise(vector<char> &gear)
{
    char first = gear.front();
    for(int i = 0; i < 7; i++) gear[i] = gear[i+1];
    gear[7] = first;
}

void Turn(vector<vector<char>> &gears, int num, int dir)
{
    // 기어의 회전 방향
    // 0: 회전하지 않음, 1: 시계, -1: 반시계
    vector<int> way(T+1, 0);
    way[num] = dir;

    // num번 기어 기준 오른쪽 기어들
    for(int i = num; i < T; i++)
    {
        if(gears[i][2] == gears[i+1][6]) break; // 같은 극 = 회전하지 않음
        way[i+1] = way[i] > 0 ? -1 : 1;
    }
    // num번 기어 기준 왼쪽 기어들
    for(int i = num; i > 1; i--)
    {
        if(gears[i][6] == gears[i-1][2]) break;
        way[i-1] = way[i] > 0 ? -1 : 1;
    }

    // way 벡터를 기반으로 회전 하는 기어들 회전 시킴
    for(int i = 1; i <= T; i++)
    {
        if(way[i] == 0) continue;
        if(way[i] == 1) ClockWise(gears[i]);
        else if(way[i] == -1) AntiClockWise(gears[i]);
    }
}

int main()
{
    cin >> T;
    vector<vector<char>> gears(T+1);
    for(int i = 1; i <= T; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < 8; j++)
        {
            gears[i].push_back(str[j]);
        }
    }

    int K; cin >> K;
    while(K--)
    {
        int num, turn; cin >> num >> turn;
        Turn(gears, num, turn);
    }

    int answer = 0;
    for(int i = 1; i <= T; i++)  if(gears[i][0] == '1') answer++;
    cout << answer;
}