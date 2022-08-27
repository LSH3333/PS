#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1000000000

int a[100010][3];
int d[100010][3];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T = 0;
    while(true)
    {
        T++;
        int N; cin >> N;
        if(N == 0) break;
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> a[i][j];
            }
        }

        d[0][0] = INF;
        d[0][1] = a[0][1];
        d[0][2] = d[0][1] + a[0][2];

        for(int i = 1; i < N; i++)
        {
            d[i][0] = min(d[i-1][0], d[i-1][1]) + a[i][0];
            d[i][1] = min({d[i-1][0], d[i-1][1], d[i-1][2], d[i][0]}) + a[i][1];
            d[i][2] = min({d[i-1][1], d[i-1][2], d[i][1]}) + a[i][2];
        }

//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0; j < 3; j++)
//        {
//            cout << d[i][j] << ' ';
//        } cout << endl;
//    }cout<<endl;

        cout << T << ". " <<  d[N-1][1] << '\n';
    }


}