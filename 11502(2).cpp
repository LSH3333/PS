#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 1000

int primeNumbers[MAX+1];

// 소수 찾기, 에라토스테네스의 체
void FindPrimeNumbers()
{
    for(int i = 2; i < MAX; i++)
        primeNumbers[i] = i;

    for(int i = 2; i < sqrt(MAX); i++)
    {
        if(primeNumbers[i] == 0) continue;

        for(int j = i * i; j <= MAX; j+=i)
        {
            primeNumbers[j] = 0;
        }
    }
}

int main()
{
    int testcase;
    cin >> testcase;
    FindPrimeNumbers();

    while(testcase--)
    {
        int n; cin >> n;
        bool flag = false;

        for(int i = 2; i <= n; i++)
        {
            // 소수 아니면 continue
            if(primeNumbers[i] == 0) continue;

            for(int j = 2; j <= n; j++)
            {
                if(primeNumbers[j] == 0) continue;

                for(int k = 2; k <= n; k++)
                {
                    if(primeNumbers[k] == 0) continue;

                    if(i+j+k == n)
                    {
                        // 낮은 소수부터 탐색하므로 오름차순으로 출력이 보장된다
                        cout << i << ' ' << j << ' ' << k << '\n';
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) cout << 0 << '\n';
    }

}