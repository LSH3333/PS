#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // 인접한 원생 둘의 키의 차
    vector<int> sub;
    for(int i = 0; i < n-1; i++)
    {
        int subtraction = v[i+1]-v[i];
        sub.push_back(subtraction);
    }

    // 내림차순 정렬
    sort(sub.begin(), sub.end(), greater<>());

    // 가장 큰 k-1 (경계가되는)을 제외한 나머지의 합 
    int ans = 0;
    for(int i = k-1; i < n-1; i++)
        ans += sub[i];

    cout << ans;

}