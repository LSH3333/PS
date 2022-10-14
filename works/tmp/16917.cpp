#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int cost = 0;

    while(true)
    {
        int x=1, y=1;
        if(X <= 0) x = 0;
        if(Y <= 0) y = 0;

        int a = cost + A*x + B*y;
        int b = cost + C * 2;
        cost = min(a, b);
        
        X--; Y--;
        if(X < 0 && Y < 0) break;
    }
    cout << cost;
}