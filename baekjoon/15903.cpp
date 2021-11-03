#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
long long ans = 0;
vector<long long> v;


int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
    }

    for(int i = 0; i < m; i++)
    {
        sort(v.begin(), v.end());
        long long sum = v[0] + v[1];
        v[0] = sum;
        v[1] = sum;
    }


    for(auto x : v)
    {
        ans += x;
    }

    cout << ans;



}