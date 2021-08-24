#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main()
{
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // 내림차순 정렬
    sort(v.begin(), v.end(), greater<>());

    for(int i = 0; i < n-2; i++)
    {
        // 삼각형 성립 조건
        if(v[i] < v[i+1] + v[i+2])
        {
            cout << v[i]+v[i+1]+v[i+2];
            return 0;
        }
    }

    // 삼각형 만들수 없음
    cout << -1;
}