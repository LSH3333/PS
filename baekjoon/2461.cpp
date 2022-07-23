#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minR, maxR;
int N, M;

void Input(vector<vector<int>> &v, int &minVal, int &maxVal)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
        if(v[i].front() < minVal) { minVal = v[i].front(); minR = i; }
        if(v[i].back() > maxVal) { maxVal = v[i].back(); maxR = i; }

    }

    // 최솟값, 최댓값이 같은 행에 있을 경우, 다음으로 큰 값을 다른 행에서 찾음
    if(minR == maxR)
    {
        maxVal = -1;
        for(int i = 0; i < N; i++)
        {
            if(i == minR) continue;
            if(v[i].back() > maxVal) { maxVal = v[i].back(); maxR = i; }
        }
    }
}

bool Check(vector<vector<int>> &v, vector<pair<int,int>> &minMax, vector<int> &tmp, int &left, int &right)
{
    int leftVal = tmp[0], rightVal = tmp[1];

    for(int i = 0; i < N; i++)
    {
        if(i == minR || i == maxR) continue;
        if(v[i][minMax[i].first] >= leftVal && v[i][minMax[i].first] <= rightVal) continue;
        if(v[i][minMax[i].second] >= leftVal && v[i][minMax[i].second] <= rightVal) continue;


    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    int minVal = 2000000000, maxVal = -1;
    vector<vector<int>> v(N, vector<int>(M));
    // 각 행들의 left, right 포인터
    vector<pair<int,int>> minMax(N, pair<int,int>({0, M-1}));
    Input(v, minVal, maxVal);


    int left = 0, right = M-1;
    while(left < M && right >= 0)
    {
        int leftVal = v[minR][left];
        int rightVal = v[maxR][right];
        // left 포인터를 움직였을 경우, right 포인터를 움직였을 경우의 차이
        int moveLeftSub = leftVal, moveRightSub = rightVal;
        if(left+1 < M) moveLeftSub = abs(v[minR][left+1] - v[maxR][right]);
        if(right-1 >= 0) moveRightSub = abs(v[maxR][right-1] - v[minR][left]);

        vector<int> tmp[2];
        if(moveLeftSub > moveRightSub)
        { tmp[0] = {v[minR][left], v[maxR][right-1]}; tmp[1] = {v[minR][left+1], v[maxR][right]};}
        else {tmp[1] = {v[minR][left+1], v[maxR][right]}; tmp[0] = {v[minR][left], v[maxR][right-1]};}


        Check(v, minMax, tmp[0], left, right);


        break;
    }


}