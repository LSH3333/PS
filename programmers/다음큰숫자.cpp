#include <iostream>
using namespace std;

// return: number of 1
int ToBinary(int n)
{
    int numberOfOne = 0;
    while(n > 0)
    {
        int left = n % 2;
        if(left == 1) numberOfOne++;
        n /= 2;
    }
    return numberOfOne;
}

int solution(int n) {
    int numOfOne = ToBinary(n);

    while(++n < 1000000)
    {
        if(ToBinary(n) == numOfOne)
            return n;
    }
}
