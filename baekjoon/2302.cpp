#include <iostream>
using namespace std;

int d[41];
bool vip[41]; // true면 vip

int main()
{
    int N; cin >> N;
    int M; cin >> M;
    for(int i = 0; i < M; i++)
    {
        int num; cin >> num;
        vip[num] = true;
    }

    d[0] = 1;
    d[1] = 1;
    for(int i = 2; i <= N; i++)
    {
        if(vip[i] || vip[i-1]) d[i] = d[i-1];
        else d[i] = d[i-1] + d[i-2];
    }
    
    cout << d[N];
}