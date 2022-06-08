#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ball
{
    int num;
    int color;
    int size;
    long long prefix; // 누적합
};

// ball 크기에 대하여 내림 차순 정렬
bool cmp(const Ball &a, const Ball &b)
{
    return a.size > b.size;
}

int N;

void CalPrefix(vector<Ball> &balls)
{
    int sum = 0;
    for(int i = 1; i <= N; i++)
    {
        sum += balls[i].size;
        balls[i].prefix = sum;
    }
}

// 크기 같거나 큰 애들 처리
void CalBasedOnSize(vector<Ball> &balls, vector<long long> &answer)
{
    // 크기 같은 공들 찾아서 누적합 통일
    int i = N;
    while(i >= 2)
    {
        int size = balls[i].size;
        // size와 다른 공의 인덱스 찾음
        int j = i-1;
        while(j >= 1 && size == balls[j].size) j--;  /////
        j++; // j까지 크기 같음
        for(int k = i-1; k >= j; k--) balls[k].prefix = balls[i].prefix; // 크기 같은 공들 누적합

        i = j;
        i--;
    }

    long long total = balls[N].prefix;
    for(i = 1; i <= N; i++)
    {
        int ballNumber = balls[i].num;
        answer[ballNumber] = total - balls[i].prefix;
    }
}

// 색은 같고, 크기 작은 애들 처리
void CalBaseOnColor(vector<Ball> &balls, vector<long long> &answer, vector<Ball> colors[])
{
    // 색깔 별로 크기 기준 내림차순 정렬
    for(int i = 1; i <= N; i++)
    {
        if(colors[i].empty()) continue;
        sort(colors[i].begin(), colors[i].end(), cmp);
    }

    // 아래서 부터 위로 누적합 계산
    for(int i = 1; i <= N; i++)
    {
        if(colors[i].empty()) continue;
        int sum = 0;
        for(int j = colors[i].size()-1; j >= 0; j--)
        {
            sum += colors[i][j].size;
            colors[i][j].prefix = sum;
        }
    }

    //
    for(int i = 1; i <= N; i++)
    {
        if(colors[i].empty()) continue;
        int j = 0;
        while(j < colors[i].size()-1)
        {
            int size = colors[i][j].size;
            int k = j;
            while(k <= colors[i].size()-1 && size == colors[i][k].size) k++;
            k--; // k까지 같은 크기

            long long target = colors[i][k+1].prefix;
            for(int a = j; a <= k; a++)
            {
                int ballN = colors[i][a].num;
                answer[ballN] -= target;
            }

            j = k;
            j++;
        }
    }


//    for(int i = 1; i <= N; i++)
//    {
//        if(colors[i].empty()) continue;
//        cout << "color: " << i << endl;
//        for(int j = 0; j < colors[i].size(); j++)
//        {
//            cout << colors[i][j].num << ',' << colors[i][j].size << ',' << colors[i][j].prefix << endl;
//        } cout << endl;
//    }
}

int main()
{
    cin >> N;
    vector<Ball> balls(200010);
    vector<Ball> colors[200010];
    vector<long long> answer(200010);
    for(int i = 1; i <= N; i++)
    {
        int c, s; cin >> c >> s;
        Ball ball{i, c, s, 0};
        balls[i] = ball;
        colors[c].push_back(ball);
    }

    // 공 크기 기준 내림차순 정렬
    sort(balls.begin()+1, balls.begin()+N+1, cmp);
    // 누적합 계산
    CalPrefix(balls);
    // 크기 같거나 큰 애들 처리
    CalBasedOnSize(balls, answer);
    // 색은 같고, 크기 작은 애들 처리
    CalBaseOnColor(balls, answer, colors);

    for(int i = 1; i <= N; i++) cout << answer[i] << '\n';
}