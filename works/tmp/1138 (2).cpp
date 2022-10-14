#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int l[n];
    for(int i = 0; i < n; i++) cin >> l[i];
    int h[n];
    for(int i = 0; i < n; i++) h[i] = n;

    for(int hei = 1; hei <= n; hei++) // 오름차순으로 배치
    {
        for(int i = 0; i < n; i++)
        {
            if(h[i] > hei)
            {
                if(--l[hei-1] < 0) { h[i] = hei; break; }
            }
        }
    }

    for(int i = 0; i < n; i++) cout << h[i] << ' ';
}