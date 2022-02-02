#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long pay = 0;
    for(int i = 1; i <= count; i++)
    {
        pay += price * i;
    }

    if(money - pay >= 0) return 0;
    return (money-pay) *-1;
}

int main()
{
    solution(3, 20, 4);
}