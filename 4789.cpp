#include <iostream>
using namespace std;

int main()
{
    int tc = 1;
    while(true)
    {
        int L,P,V;
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;

        int div = V / P;
        int left = V % P;
        
        int ans;
        if(left > L)
        {
            ans = L * div + L;
        }
        else
        {
            ans = L * div + left;
        }

        cout << "Case " << tc << ": " << ans << '\n';
        tc++;
    }

}