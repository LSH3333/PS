#include <iostream>
using namespace std;

double W, L, D;
// i번째 게임에서 j점일 확률
double d[21][4000];

int main()
{
    cin >> W >> L >> D;

    d[0][2000] = 1;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 1000; j < 3500; j++)
        {
            if(d[i][j] == 0) continue;
            d[i+1][j+50] += d[i][j] * W;
            d[i+1][j] += d[i][j] * D;
            d[i+1][j-50] += d[i][j] * L;
        }
    }

    double bronze = 0, silver = 0, gold = 0, platinum = 0, diamond = 0;
    for(int j = 1000; j <= 1499; j++) bronze += d[20][j];
    for(int j = 1500; j <= 1999; j++) silver += d[20][j];
    for(int j = 2000; j <= 2499; j++) gold += d[20][j];
    for(int j = 2500; j <= 2999; j++) platinum += d[20][j];
    for(int j = 3000; j <= 3499; j++) diamond += d[20][j];

    printf("%0.8f\n", bronze);
    printf("%0.8f\n", silver);
    printf("%0.8f\n", gold);
    printf("%0.8f\n", platinum);
    printf("%0.8f\n", diamond);
}