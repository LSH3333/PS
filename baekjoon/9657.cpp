#include <iostream>
using namespace std;

// true시 돌이 N개일때 SK가 승리 
bool d[1010];

int main()
{
    int N; cin >> N;
    d[1] = true;
    d[2] = false;
    d[3] = true;
    d[4] = true;
    for(int i = 5; i <= N; i++)
    {
        if(!d[i-1] || !d[i-3] || !d[i-4]) d[i] = true;
        else d[i] = false;
    }

    if(d[N]) cout << "SK";
    else cout << "CY";
}