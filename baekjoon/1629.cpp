#include <iostream>
using namespace std;

long long dfs(int a, int b, int c)
{
    if(b == 1)
    {
        return a % c;
    }
    long long n = dfs(a, b/2, c);
    if(b % 2 == 0)
    {
        return (n * n) % c;
    }
    else
    {
        return (((n * n) % c) * a) % c;
    }
}

int main()
{
    int A, B, C; cin >> A >> B >> C;
    cout << dfs(A, B, C);
}