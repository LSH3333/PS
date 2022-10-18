#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int N; cin >> N;
    bitset<32> b1, b2;
    b1 = N;
    b2 = -N;

    int cnt = 0;
    for(int i = 0; i < 32; i++)
    {
        if(b1[i] != b2[i]) cnt++;
    }
    cout << cnt;
}