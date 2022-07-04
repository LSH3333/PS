#include <iostream>
using namespace std;

pair<int,int> AB[31];

int main()
{
    int D, K; cin >> D >> K;
    AB[1] = {1, 0};
    AB[2] = {0, 1};
    for(int i = 3; i <= D; i++)
    {
        AB[i].first = AB[i-1].first + AB[i-2].first;
        AB[i].second = AB[i-1].second + AB[i-2].second;
    }

    int A = AB[D].first, B = AB[D].second;
    int a=0, b=0;
    for(int i = 1; i <= 100000; i++)
    {
        a = i * A;
        int k = K - a;
        if(k % B != 0) continue;
        a = i;
        b = k / B;
        break;
    }
    cout << a << '\n' << b;
}