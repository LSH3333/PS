#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,B;
int map[501][501];
vector<int> v;

int T = 99999999;
int H = 99999999;

// 높이를 num 으로 통일시켜본다
void Calculate(int num)
{
    int removed = 0;
    int added = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 크기가 num보다 낮다면
            if(map[i][j] < num)
            {
                // 블록을 쌓아야함
                added += num - map[i][j];
            }
                // 크기가 num보다 높다면
            else if(map[i][j] > num)
            {
                // 블록을 제거해야함
                removed += map[i][j] - num;
            }
        }
    }

    // 작업 후 인벤토리에 남아 있는 블록의 수
    int remain = B + removed - added;
    // 인벤토리에 남아있는 블록의수가 0보다 작아진다면 높이를 num으로 통일하는 작업은 불가능하다
    if(remain < 0)
    {
        return;
    }

    // 위 조건을 통과했다면 작업이 가능한 경우
    int time = 2 * removed + added;

    if(time < T)
    {
        T = time;
        H = num;
    }
    // 같은 시간이 걸릴때
    if(time == T)
    {
        // 현재 높이가 더 높으면
        if(num > H)
        {
            T = time;
            H = num;
        }
    }
}

int main()
{
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            // 벡터 v에는 중복되지 않는 숫자들이 들어가게됨
            bool overlap = false;
            for(int x : v)
            {
                if(x == map[i][j])
                {
                    overlap = true;
                    break;
                }
            }
            if(!overlap)
                v.push_back(map[i][j]);
        }
    }

    int origin_B = B;
    // 정렬
    sort(v.begin(), v.end());

    // 가장 작은 높이에서부터 가장 높은 높이까지 계산
    for(int i = v[0]; i <= v[v.size()-1]; i++)
    {
        B = origin_B;
        Calculate(i);
    }


    cout << T << ' ' << H;
}