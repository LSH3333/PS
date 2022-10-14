#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[100001] = {0,};
    int d[100001] = {0,};
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        a[i] = num;
    }
    
    d[0] = a[0];
    int answer = d[0];
    for(int i = 1; i < n; i++)
    {
        d[i] = max(d[i-1]+a[i], a[i]);
        answer = max(answer, d[i]);
    }

    cout << answer;
}