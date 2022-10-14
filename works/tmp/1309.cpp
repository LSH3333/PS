#include <iostream>
#define MOD 9901
using namespace std;

int d[100010][3];

int main()
{
    int n; cin >> n;

    // 세로 길이 n일때 n번 행에 사자가 없는 경우
    d[1][0] = 1;
    // 세로 길이 n일때 n번 행에 왼쪽만 사자가 있는 경우
    d[1][1] = 1;
    // 세로 길이 n일때 n번 행에 오른쪽만 사자가 있는 경우
    d[1][2] = 1;

    for(int i = 2; i <= n; i++)
    {
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % MOD;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % MOD;
        d[i][2] = (d[i-1][0] + d[i-1][1]) % MOD;
    }

//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 0; j < 3; j++)
//        {
//            cout << d[i][j] << ' ';
//        } cout << endl;
//    }

    cout << (d[n][0] + d[n][1] + d[n][2]) % MOD;

}