#include <iostream>
using namespace std;

int t;
int button[3] = {300,60,10};

int main()
{
    cin >> t;

    int cnt[3] = {0,};
    for(int i = 0; i < 3; i++)
    {
        while(t >= button[i])
        {
            t -= button[i];
            cnt[i]++;
        }
    }

    if(t == 0)
    {
        for(int i = 0; i < 3; i++)
            cout << cnt[i] << ' ';
    }
    else
        cout << -1;


}