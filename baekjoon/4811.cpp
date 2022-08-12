#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        // day, W, H
        long long d[62][62][62] = {};
        int N; cin >> N;
        if(N == 0) break;
        d[1][N-1][1]++;

        for(int day = 2; day <= 2*N; day++)
        {
            for(int W = 0; W <= N; W++)
            {
                for(int H = 0; H <= N; H++)
                {
                    if(d[day-1][W][H] == 0) continue;
                    // w
                    if(W > 0) d[day][W-1][H+1] += d[day-1][W][H];
                    // h
                    if(H > 0) d[day][W][H-1] += d[day-1][W][H];
                }
            }
        }


        long long answer = 0;
        for(int w = 0; w <= 2*N; w++)
        {
            for(int h = 0; h <= 2*N; h++)
            {
                answer += d[2*N][w][h];
            }
        }
        cout << answer << '\n';
    }
}