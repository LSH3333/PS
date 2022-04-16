#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;


bool CalRight(vector<int> &line, int maxIdx)
{
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

        // 다음 L개에 경사로 건설 가능한지
        for(int j = i+1; j < i+1+L; j++)
        {
            if(j >= N) return false; // 범위 벗어나면 불가능
            // 다음 L개가 같은 레벨아니라면 불가능
            if(line[j] != nextLevel) return false;
        }

        // 경사로 건설 가능, 이동
        i += L;
    }

    cout << "RIGHT TRUE" << endl;
    return true;
}

bool CalLeft(vector<int> &line, int maxIdx)
{
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
    cout << "LEFT TRUE" << endl;
    return true;
}

bool CalLine(vector<int> &line)
{
    int maxIdx = max_element(line.begin(), line.end())-line.begin();
    cout << "maxIdx: " << maxIdx << endl;
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
    cout << "row" << endl;
    for(int i = 0; i < N; i++)
    {
        cout << "------ i: " << i << "--------" << endl;
        if(CalLine(arr[i])) { cout << i << endl; answer++; }
    }
    // col
    cout << endl << endl;
    cout << "col" << endl;
    for(int j = 0; j < N; j++)
    {
        cout << "------ j: " << j << "--------" << endl;
        vector<int> line;
        for(int i = 0; i < N; i++)
        {
            line.push_back(arr[i][j]);
        }
        if(CalLine(line)) { cout << j << endl; answer++; }
    }

    cout << "answer: " << answer;
}