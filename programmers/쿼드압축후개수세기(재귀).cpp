#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Arr;

void Cal(int r, int c, int size, vector<int> &answer)
{
    int flagNum = Arr[r][c];
    bool flag = true;
    for(int i = r; i < r + size; i++)
    {
        for(int j = c; j < c + size; j++)
        {
            if(flagNum != Arr[i][j])
            {
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }

    // 정사각형이 모두 같은수
    // 재귀하지 않고 바로 리턴
    if(flag)
    {
        answer[flagNum]++;
        return;
    }

    Cal(r, c, size / 2, answer);
    Cal(r, c+size/2, size/2, answer);
    Cal(r+size/2, c, size/2, answer);
    Cal(r+size/2, c+size/2, size/2, answer);
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer(2,0);
    Arr = arr;
    Cal(0, 0, arr.size(), answer);
    return answer;
}
