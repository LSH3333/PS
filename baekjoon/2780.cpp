#include <iostream>
#include <vector>
using namespace std;

#define MOD 1234567
// d[i][j] : 길이 i 면서 j로 끝나는 숫자의 갯수
long long d[1010][10];
vector<int> adjacent[10] =
        {
                {7},
                {2,4},
                {1,3,5},
                {2,6},
                {1,5,7},
                {2,4,6,8},
                {3,5,9},
                {0,4,8},
                {5,7,9},
                {6,8}
        };

int main()
{
    int N = 1000;
    for(int i = 0; i < 10; i++) d[1][i] = 1;

    for(int i = 2; i <= N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            long long sum = 0;
            for(auto x : adjacent[j])
            {
                sum += d[i-1][x];
            }
            d[i][j] = sum % MOD;
        }
    }

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        long long answer = 0;
        for(int i = 0; i < 10; i++) answer += d[n][i] % MOD;
        cout << answer % MOD << '\n';
    }

}