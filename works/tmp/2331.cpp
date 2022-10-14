#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int A, P;

int Cal(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += pow(n%10, P);
        n /= 10;
    }
    return sum;
}

int main()
{
    cin >> A >> P;
    int cnt = 1;
    map<int,int> m;
    m[A] = cnt++;

    while(true)
    {
        A = Cal(A);
        if(m[A] > 0) { cout << m[A]-1; break; }
        m[A] = cnt++;
    }
}