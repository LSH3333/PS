#include <iostream>
#include <cmath>
#define MAX 1000001
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
    ios::sync_with_stdio(false); cin.tie(NULL);
    FindPrimeNumbers();

    while(true)
    {
        int n; cin >> n;
        if(n == 0) break;
        int a = -1, b = -1;
        for(int i = 1; i < n; i+=2)
        {
            if(primeNumber[i] != 0 && primeNumber[n-i] != 0)
            {
                a = i;
                b = n-i;
                break;
            }
        }

        if(a == -1 && b == -1) cout << "Goldbach's conjecture is wrong.\n";
        else cout << n << " = " << a << " + " << b << '\n';
    }

}