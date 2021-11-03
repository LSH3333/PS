#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 10

int n;
int ans = 999999999;
int map[MAX][MAX];
bool mark[MAX][MAX];


// map[r][c]를 중심으로 하는 꽃을 심을수 있는지 확인
bool CanIPlantFlowerHere(int r, int c)
{
    // 화단을 벗어나면 심을수 없음
    if(r-1 < 0 || r+1 >= n) return false;
    if(c-1 < 0 || c+1 >= n) return false;

    // 꽃이 이미 심어져있다면 심을수 없음
    if(mark[r][c] || mark[r-1][c] || mark[r][c+1] || mark[r][c-1] || mark[r+1][c])
        return false;

    // 모든 조건 통과 = 꽃 심을수 있음
    return true;
}

// 꽃을 심어본다
void PlantFlower(int r, int c)
{
    mark[r][c] = true;
    mark[r-1][c] = true;
    mark[r][c+1] = true;
    mark[r][c-1] = true;
    mark[r+1][c] = true;
}

// 꽃을 파낸다
void DigFlower(int r, int c)
{
    mark[r][c] = false;
    mark[r-1][c] = false;
    mark[r][c+1] = false;
    mark[r][c-1] = false;
    mark[r+1][c] = false;
}

// 3개의 꽃이 심어진 상태에서 가격이 얼마인지
int CalculatePrice()
{
    int price = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(mark[i][j])
                price += map[i][j];
        }
    }
    return price;
}

// 모든 꽃을 심을수 있는 경우를 탐색한다
void Flower(int depth)
{
    if(depth == 3)
    {
        ans = min(ans, CalculatePrice());
        return;
    }

    for(int r = 1; r < n-1; r++)
    {
        for(int c = 1; c < n-1; c++)
        {
            if(mark[r][c]) continue;

            // 해당 지점에 꽃을 심을수 있으면 심는다
            if(CanIPlantFlowerHere(r,c))
            {
                PlantFlower(r,c);
                Flower(depth+1);
                DigFlower(r,c);
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    Flower(0);

    cout << ans;


}

