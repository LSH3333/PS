#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    // 오름차순 정렬
    sort(v.begin(), v.end());

    int ans = 0;
    int time = 0;
    int prev = 0;
    for(int i = 0; i < n; i++)
    {
        prev = time;
        time = prev + v[i];
        ans += time;
    }
    cout << ans;
}
