#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int tempa = a, tempb = b;
    a = min(tempa, tempb);
    b = max(tempa, tempb);

    while(true)
    {
        if(b % 2 == 0 && b-a == 1) break;

        if(a % 2 == 0) a /= 2;
        else a = (a + 1) / 2;

        if(b % 2 == 0) b /= 2;
        else b = (b + 1) / 2;

        answer++;
    }

    return answer;
}