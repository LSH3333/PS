#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,l;
vector<int> pipe;

int main()
{
    cin >> n >> l;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pipe.push_back(num);
    }

    // 오름차순 정렬
    sort(pipe.begin(), pipe.end());

    int cnt = 0;
    double end = 0;
    for(int i = 0; i < n; i++)
    {
        // 이전에 붙인 테이프가 현재 물이 세는곳 위치를 커버하면 continue 
        if(end > pipe[i]) continue;
        end = pipe[i]-0.5+l;

        cnt++;
    }
    cout << cnt;
}