#include <iostream>
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
    // 먼저 1000까지의 소수들을 찾는다
    FindPrimeNumbers();

    int testcase;
    cin >> testcase;

    for(int tc = 0; tc < testcase; tc++)
    {
        int a,b,c;
        int n; // 31이 소수 3개로 이루어질수 있는가?
        cin >> n;

        // n2가 소수 두개로 이루어질수 있는지 판단
        bool flag = false;
        // i: 23, 31에서 소수인 23을 뺐을때 8이고, 8이 소수 두개로 이루어질수 있는가?
        for(int i = n-1; i >= 2; i--)
        {
            if(primeNumbers[i] == 0) continue;

            int n2 = n - i; // 8


            for(int j = n2-1; j >= 2; j--)
            {
                if(primeNumbers[j] == 0) continue;
                // 소수가 맞다면
                if(primeNumbers[n2-j] != 0)
                {
                    a = n2-j;
                    b = j;
                    c = i;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        // 가능한 소수를 찾았다
        if(flag)
            cout << a << ' ' << b << ' ' << c << '\n';
        else // 가능한 소수가 없다
            cout << 0 << '\n';
    }

}