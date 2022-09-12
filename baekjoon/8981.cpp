#include <iostream>
using namespace std;

int N;
int Y[31];
int X[31];

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> Y[i];

    int count = 0;
    int xIdx = 0;
    while(count < N)
    {
        while(X[xIdx] != 0)
        {
            xIdx = (xIdx + 1) % N;
        }
        X[xIdx] = Y[count];

        xIdx = (xIdx + Y[count]) % N;
        count++;
    }

    cout << N << '\n';
    for(int i = 0; i < N; i++) cout << X[i] << ' ';
}