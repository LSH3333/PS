#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<int> v;
vector<int> dis;

int main()
{
    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for(int i = 1; i < n; i++)
    {
        int sub = v[i] - v[i-1];
        dis.push_back(sub);
    }

    // 거리를 내림차순 정렬
    sort(dis.begin(), dis.end(), greater<>());
    // k-1개의 가장 큰 값 제외하고 더함
    int ans = 0;
    for(int i = k-1; i < dis.size(); i++)
        ans += dis[i];

    cout << ans;

}