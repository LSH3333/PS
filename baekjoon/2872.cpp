#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int target = n;
    int cnt = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(v[i] == target)
        {
            cnt++;
            target--;
        }
    }
    cout << n-cnt;
}

