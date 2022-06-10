#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200010
using namespace std;

struct Ball
{
    int num;
    int color;
    int size;
};

// 크기 기준 오름차순 정렬, 크기 같다면 색깔 기준 정렬
bool cmp(const Ball &a, const Ball &b)
{
    if(a.size == b.size) return a.color < b.color;
    return a.size < b.size;
}

int colors[MAX];
int sizes[MAX];
int answers[MAX];

int main()
{
    int N; cin >> N;
    vector<Ball> balls(N+1);
    for(int i = 1; i <= N; i++)
    {
        int color, size; cin >> color >> size;
        Ball ball{i, color, size};
        balls[i] = ball;
    }

    sort(balls.begin()+1, balls.end(), cmp);

    int prefix = 0; // 크기 누적합
    for(int i = 1; i <= N; i++)
    {
        int num = balls[i].num;
        int size = balls[i].size;
        int color = balls[i].color;

        colors[color] += size; // 각 색깔 별 누적합
        sizes[size] += size; // 각 크기 별 누적합
        prefix += size;

        // 현재까지 누적합 - 현재까지 색의 누적합 - 현재까지 크기의 누적합 + 내 크기
        answers[num] = prefix - colors[color] - sizes[size] + size;
        // 이전 공과 색과 크기가 같다면 동일하게 처리
        if(i != 1 && (balls[i-1].size == size) && (balls[i-1].color == color))
            answers[num] = answers[balls[i-1].num];
    }

    for(int i = 1; i <= N; i++) cout << answers[i] << '\n';
}