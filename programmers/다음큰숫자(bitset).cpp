#include <iostream>
#include <bitset>
using namespace std;

int solution(int n)
{
    bitset<20> bit(n);
    int cnt = bit.count();

    while(++n)
    {
        bitset<20> b(n);
        if(b.count() == cnt) return n;
    }
}