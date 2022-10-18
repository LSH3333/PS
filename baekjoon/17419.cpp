#include <iostream>
using namespace std;

int main()
{
    int N;
    string bit;
    cin >> N >> bit;
    int cnt = 0;
    for(auto x : bit)
    {
        if(x == '1') cnt++;
    }
    cout << cnt;
}