#include <iostream>
using namespace std;

int R,B;

int main()
{
    cin >> R >> B;

    for(int i = R/2-1; i > 0; i--)
    {
        int height_total = i * 2;
        int width_total = R - height_total+4;

        int length = (height_total/2) * (width_total/2);

        if(length == R+B)
        {
            if(height_total > width_total)
            {
                cout << height_total/2 << ' ' << width_total/2;
                return 0;
            }
            else
            {
                cout << width_total/2 << ' ' << height_total/2;
                return 0;
            }
        }

    }
}
