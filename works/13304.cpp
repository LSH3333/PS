#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[7][2];

int main()
{
    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int gender, grade; cin >> gender >> grade;
        arr[grade][gender]++;
    }

    vector<int> v;
    v.push_back(arr[1][0] + arr[1][1] + arr[2][0] + arr[2][1]);
    v.push_back(arr[3][0] + arr[4][0]);
    v.push_back(arr[3][1] + arr[4][1]);
    v.push_back(arr[5][0] + arr[6][0]);
    v.push_back(arr[5][1] + arr[6][1]);

    int ans = 0;
    for(auto x : v)
    {
        ans += x / K;
        if(x % K != 0) ans++;
    }

    cout << ans;
}