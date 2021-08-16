#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int c;
        cin >> c;

        int q=0,d=0,n=0,p=0;
        while(c > 0)
        {
            if(c >= 25)
            {
                q++;
                c -= 25;
            }
            else if(c >= 10)
            {
                d++;
                c -= 10;
            }
            else if(c >= 5)
            {
                n++;
                c -= 5;
            }
            else if(c >= 1)
            {
                p++;
                c -= 1;
            }
        }

        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }


}