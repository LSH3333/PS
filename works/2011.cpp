#include <iostream>
using namespace std;
#define MOD 1000000

int d[5010][2];

int main()
{
    string s; cin >> s;
    int N = (int)s.size();

    if(s[0] != '0') { d[0][0] = 1; d[0][1] = 0; }

    for(int i = 1; i < N; i++)
    {
        int n1 = s[i-1]-'0';
        int n2 = s[i]-'0';

        if(n2 != 0)
            d[i][0] = (d[i-1][0] + d[i-1][1]) % MOD;

        if(n1*10+n2 >= 1 && n1*10+n2 <= 26)
            d[i][1] = d[i-1][0] % MOD;
    }
    
    cout << (d[N-1][0] + d[N-1][1]) % MOD;
}