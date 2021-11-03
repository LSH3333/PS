#include <iostream>
#include <cmath>
#include <string>
#define MAX 1010001
using namespace std;

int n;
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

// int형인 숫자를 받아서 string으로 변환해서 팰린드롬인지 판별한다
bool IsItPalindrome(int num)
{
    string str = to_string(num);
    int mid = str.size() / 2;

    for(int i = 0; i < mid; i++)
    {
        if(str[i] != str[str.size()-1-i])
            return false;
    }
    return true;
}

int main()
{
    cin >> n;

    FindPrimeNumbers();


    for(int i = n; i <= MAX; i++)
    {
        // 소수인것들 중에서
        if(primeNumber[i] == 0) continue;

        // 소수이면서 팰린드롬이라면
        if(IsItPalindrome(primeNumber[i]))
        {
            cout << primeNumber[i];
            return 0;
        }
    }


}