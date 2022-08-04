#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--)
    {
        int answer = 10000000;
        int R[6];
        int C[6];
        for(int i = 0; i < 3; i++)
        {
            cin >> C[i] >> R[i];
            R[i+3] = C[i];
            C[i+3] = R[i];
        }

        for(int i = 0; i < 6; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                for(int k = 0; k < 6; k++)
                {
                    if(i%3==j%3 || j%3==k%3 || k%3==i%3) continue; // 같은 박스

                    int r = max({R[i], R[j], R[k]});
                    int c = C[i] + C[j] + C[k];
                    answer = min(answer, r*c);

                    r = R[i] + max(R[j],R[k]);
                    c = max(C[i], C[j]+C[k]);
                    answer = min(answer, r*c);
                }
            }
        }
        cout << answer << '\n';
    }



}