#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
vector<int> v;

int main()
{
    cin >> n >> l;
    v.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        // 스네이크버드가 먹을수 있는 경우
        if(v[i] <= l)
        {
            l++;
        }
        else // 못먹는 경우
        {
            cout << l;
            return 0;
        }
    }
    cout << l;
}
