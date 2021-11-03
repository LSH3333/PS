#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a,b,n;
vector<int> v;

int main()
{
    cin >> a >> b >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    v.push_back(a);
    v.push_back(b);

    sort(v.begin(), v.end(), less<>());

    int left = 0, right = 0;
    int direct = abs(b-a);
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == b)
        {
            if(i == 0)
            {
                left = 9999;
                right = v[i+1] - b;
            }
            else if(i == v.size()-1)
            {
                left = b - v[i-1];
                right = 9999;
            }
            else
            {
                left = b - v[i-1];
                right = v[i+1] - b;
            }
            break;
        }
    }

    //cout << left << ' ' << right << ' ' << direct << endl;

    // 즐겨찾기 거쳐서 가는 경우는 한번더 눌러야함

    int ans = min({left+1, right+1, direct});
    cout << ans;



}