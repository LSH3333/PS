#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 5001

int n;
int ans = 0;

vector<int> v[MAX];

int main()
{
    cin >> n;
    // 같은 color는 같은 행에 푸쉬
    for(int i = 0; i < n; i++)
    {
        int point, color;
        cin >> point >> color;

        v[color].push_back(point);
    }

    // 색깔은 1부터 n까지
    for(int i = 1; i <= n; i++)
    {
        // 해당 행이 비어있으면 continue
        if(v[i].empty()) continue;

        // 오름차순으로 정렬
        sort(v[i].begin(), v[i].end());

        for(int j = 0; j < v[i].size(); j++)
        {
            // 제일 왼쪽점의 화살표는 바로 오른쪽점을 향할수 밖에 없다
            if(j == 0)
                ans += abs(v[i][0] - v[i][1]);

            // 제일 오른쪽점의 화살표는 바로 왼쪽점을 향할수 밖에 없다
            else if(j == v[i].size()-1)
                ans += abs(v[i][j] - v[i][j-1]);

            // 중간 점들
            else
            {
                // 양쪽 같은색 점 중, 가까운 곳의 거리를 합한다
                int a = abs(v[i][j-1] - v[i][j]);
                int b = abs(v[i][j+1] - v[i][j]);
                ans += min(a,b);
            }
        }
    }
    cout << ans;
}
