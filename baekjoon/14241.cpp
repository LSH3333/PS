#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    long long slime;
    cin >> slime;

    long long score = 0;

    for(int i = 1; i < n; i++)
    {
        long long slime2;
        cin >> slime2;

        score += slime * slime2;
        slime = slime + slime2;
    }

    cout << score;
}