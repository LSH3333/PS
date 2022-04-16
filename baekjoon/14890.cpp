#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;

// maxIdx 기준 오른쪽 탐색, 끝까지 이동 가능하면 참 반환
bool CalRight(vector<int> &line, int maxIdx)
{
    vector<bool> mark(N, false);
    // right
    for(int i = maxIdx; i < N-1;)
    {
        int curLevel = line[i];
        int nextLevel = line[i+1];
        // 현재 레벨과 다음 레벨이 같다면 그냥 이동가능
        if(curLevel == nextLevel)
        {
            i++; continue;
        }

        // 다음 레벨이 1차이 나는것 아니면 불가능
        if(nextLevel > curLevel+1 || nextLevel < curLevel-1) return false;

        // 내리막길
        if(nextLevel == curLevel-1)
        {
            // 다음 L개에 경사로 건설 가능한지
            for(int j = i+1; j < i+1+L; j++)
            {
                if(j >= N) return false; // 범위 벗어나면 불가능
                // 다음 L개가 같은 레벨 아니라면 불가능
                if(line[j] != nextLevel) return false;
            }

            // 경사로 건설 가능, 이동
            for(int j = i+1; j < i+1+L; j++) mark[j] = true;
            i += L;
        }
            // 오르막길
        else
        {
            // 현재 칸 포함 이전 L개의 레벨이 같은지, 경사로 있는지 확인
            bool canBuild = true;
            for(int j = i; j > i-L; j--)
            {
                if(line[j] != curLevel || mark[j])
                { canBuild = false; break; }
            }
            // 같았다면 뒤에서 부터 경사로 설치후 이동
            if(canBuild) i++;
            else return false;
        }
    }

    return true;
}

// maxIdx 기준 왼쪽 탐색
bool CalLeft(vector<int> &line, int maxIdx)
{
    vector<bool> mark(N, false);
    // left
    for(int i = maxIdx; i > 0;)
    {
        int curLevel = line[i];
        int nextLevel = line[i-1];
        // 현재 레벨과 다음 레벨이 같다면 그냥 이동가능
        if(curLevel == nextLevel)
        {
            i--; continue;
        }

        // 다음 레벨이 1차이 나는것 아니면 불가능
        if(nextLevel > curLevel+1 || nextLevel < curLevel-1) return false;

        // 내리막길
        if(nextLevel == curLevel-1)
        {
            // 다음 L개에 경사로 건설 가능한지
            for(int j = i-1; j > i-(1+L); j--)
            {
                if(j < 0) return false; // 범위 벗어나면 불가능
                // 다음 L개가 같은 레벨 아니라면 불가능
                if(line[j] != nextLevel) return false;
            }

            // 경사로 건설 가능, 이동
            i -= L;
        }
        else // 오르막길
        {
            bool canBuild = true;
            for(int j = i; j < i+L; j++)
            {
                if(line[j] != curLevel || mark[j])
                { canBuild = false; break; }
            }
            if(canBuild) i--;
            else return false;
        }

    }

    return true;
}

// 행 or 열 받아서 해당하는 행이나 열이 이동가능한 도로인지 판단, 이동 가능하면 참 반환
bool CalLine(vector<int> &line)
{
    int maxIdx = max_element(line.begin(), line.end())-line.begin();

    // left, right 모두 이동 가능하면 참 반환
    if(CalRight(line, maxIdx) && CalLeft(line, maxIdx)) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> L;
    vector<vector<int>> arr(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    // row
    for(int i = 0; i < N; i++)
    {
        if(CalLine(arr[i])) {  answer++; }
    }
    // col
    for(int j = 0; j < N; j++)
    {
        vector<int> line;
        for(int i = 0; i < N; i++)
        {
            line.push_back(arr[i][j]);
        }
        if(CalLine(line)) {answer++; }
    }

    cout << answer;
}