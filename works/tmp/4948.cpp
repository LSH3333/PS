#include <iostream>
#include <cmath>
#define MAX ((123456 * 2) + 10)

using namespace std;

int primeNumber[MAX];

// 에라토스테네스의 체
void FindPrimeNumbers()
{
    // 숫자 채워넣음
    for(int i = 2; i < MAX; i++)
    {
        primeNumber[i] = i;
    }

    for(int i = 2; i < sqrt(MAX); i++)
    {
        // 이미 소수로 판별 났다면 continue
        if(primeNumber[i] == 0) continue;
        // i의 배수들을 0으로 치환
        for(int j = i * i; j < MAX; j += i)
        {
            // 소수 아닌것 표시
            primeNumber[j] = 0;
        }
    }
}

int main()
{
    FindPrimeNumbers();

    int n = -1;
    while(true)
    {
        cin >> n;
        if(n == 0) break;
        int cnt = 0;
        for(int i = n+1; i <= 2*n; i++)
        {
            if(primeNumber[i] != 0) cnt++;
        }
        cout << cnt << '\n';
    }
}