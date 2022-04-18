#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int arr[110][110];

// 현재 세대의 방향 정보 받아, 다음 세대 방향 정보 리턴
vector<int> NextGenDir(vector<int> &d)
{
    vector<int> next = d;
    reverse(d.begin(), d.end());
    for(auto &x : d)
    {
        x = (x + 1) % 4;
        next.push_back(x);
    }
    return next;
}

int main()
{
    int N; cin >> N;
    while(N--)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        // 방향 구함
        vector<int> dir; dir.push_back(d);
        for(int i = 1; i <= g; i++)
        {
            dir = NextGenDir(dir);
        }

        // arr에 기록
        arr[y][x] = true;
        for(auto direction : dir)
        {
            y = y + dy[direction];
            x = x + dx[direction];
            arr[y][x] = true;
        }
    }
    
    int answer = 0;
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            bool isCor = (arr[i][j] && arr[i][j+1] && arr[i+1][j] && arr[i+1][j+1]);
            if(isCor) answer++;
        }
    }
    cout << answer;

}