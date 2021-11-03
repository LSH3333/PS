#include <iostream>
#include <vector>
using namespace std;

int n;
int coin[6] = {500,100,50,10,5,1};

int main()
{
    cin >> n;

    int pay = 1000-n;
    int cnt = 0;
    for(int i = 0; i < 6; i++)
    {
        while(pay >= coin[i])
        {
            pay -= coin[i];
            cnt++;
        }
    }

    cout << cnt;
}
