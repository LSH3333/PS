#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000010

int p[MAX];

void FindPrime()
{
    for(int i = 2; i < MAX; i++) p[i] = i;

    for(int i = 2; i * i < MAX; i++)
    {
        if(p[i] == 0) continue;
        // 소수 아닌것 0으로 처리
        for(int j = i*i; j <= MAX; j += i) p[j] = 0;
    }
}

int main()
{
    FindPrime();
    int n, m; cin >> n >> m;
    for(int i = n; i <= m; i++)
    {
        if(p[i] == 0) continue;
        cout << p[i] << '\n';
    }
}