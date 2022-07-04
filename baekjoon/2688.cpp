#include <iostream>
using namespace std;

// [i][j] : i자리의 수에서 뒤가 j로 끝나는 숫자의 갯수
long long d[70][10];

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        // 1자리 일때는 0~9 모두 1개만 가능
        for(int i = 0; i <= 9; i++) d[1][i] = 1;

        for(int i = 2; i <= N; i++)
        {
            long long add = 0;
            for(int j = 0; j <= 9; j++)
            {
                add += d[i-1][j];
                d[i][j] = add;
            }
        }

        long long answer = 0;
        for(int i = 0; i <= 9; i++) answer += d[N][i];
        cout << answer << '\n';
    }
}