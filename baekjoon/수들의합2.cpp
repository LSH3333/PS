#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int num; cin >> num;
        v.push_back(num);
    }

    int left = 0, right = 0, sum = 0, cnt = 0;
    while(right <= v.size())
    {
        if(sum < m)
        {
            sum += v[right];
            right++;
        }
        else if(sum > m)
        {
            sum -= v[left];
            left++;
        }
        else if(sum == m)
        {
            cnt++;
            sum += v[right];
            right++;
        }
    }
    cout << cnt;
}