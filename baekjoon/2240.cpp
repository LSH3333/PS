#include <iostream>
using namespace std;

// d[i] = j : i초에 j 위치에 자두 떨어짐
int times[1010];
// d[i][j] : j초 까지 총 i번 움직였을때 {현재 위치, 먹은 자두 최댓값}
pair<int,int> d[35][1010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T, W; cin >> T >> W;
    for(int i = 1; i <= T; i++) { int sec; cin >> sec; times[i] = sec-1;}

    d[0][1] = {0, times[1] == 0 ? 1 : 0};
    d[1][1] = {1, times[1] == 1 ? 1 : 0};
    int answer = max(d[0][1].second, d[1][1].second);

    for(int c = 2; c <= T; c++)
    {
        for(int r = 0; r <= W; r++)
        {
            if(r == 0)
            {
                // not move
                pair<int,int> b = d[r][c-1];
                if(b.first == times[c]) b.second++;
                d[r][c] = b;
            }
            else
            {
                // move
                pair<int,int> a = {(d[r-1][c-1].first+1)%2, d[r-1][c-1].second};
                if(a.first == times[c]) a.second++;
                // not move
                pair<int,int> b = d[r][c-1];
                if(b.first == times[c]) b.second++;

                if(a.second > b.second) d[r][c] = a;
                else d[r][c] = b;
            }
            answer = max(answer, d[r][c].second);
        }
    }

    cout << answer;
    
}