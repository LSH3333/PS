#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    if(N == 1) { cout << "A"; return 0; }
    if(N == 2)
    {
        if(v[0] == v[1]) { cout << v[0]; return 0;}
        else { cout << "A"; return 0; }
    }


    int a, b;
    if(v[0] == v[1])
    {
        a = 0; b = v[1];
    }
    else
    {
        a = (v[1]-v[2]) / (v[0]-v[1]);
        b = v[1] - v[0] * a;
    }

    for(int i = 1; i <= N-2; i++)
    {
        int res = v[i] * a + b;
        if(res != v[i+1]) { cout << "B"; return 0; }
    }

    cout << v[N-1] * a + b;
}