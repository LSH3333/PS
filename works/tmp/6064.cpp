#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int big,small; // M,N 중 큰 값
        int bigVal, smallVal; // 그에 따른 x,y값
        if(M < N) { big = N; bigVal = y; small = M; smallVal = x;}
        else { big = M; bigVal = x; small = N; smallVal = y;}

        int temp = smallVal;
        int sub = big - small;
        int cnt = 0;
        bool found = false;
        while(true)
        {
            if(temp == bigVal) {found = true; break;}

            if(temp - sub <= 0)
            {
                int subTmp = temp - sub;
                temp = big - (subTmp * -1);
            }
            else temp -= sub;

            // temp값이 다시 smallVal로 돌아온다면 유효하지 않은 값
            if(temp == smallVal) break;

            cnt++;
        }

        if(!found) cout << -1 << '\n';
        else cout << (small * cnt) + smallVal << '\n';
    }
}