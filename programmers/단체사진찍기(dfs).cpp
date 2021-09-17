#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int answer = 0;
bool mark[8];


void DFS(int depth, vector<char> v,vector<string> data, char friends[])
{
    // 8자리 순열 다 만들어짐
    if(depth == 8)
    {
        for(int i = 0; i < data.size(); i++)
        {
            int friend1Idx= find(v.begin(), v.end(), data[i][0]) - v.begin();
            int friend2Idx= find(v.begin(), v.end(), data[i][2]) - v.begin();
            char op = data[i][3];
            int targetGap = data[i][4] - '0';
            int gap = abs(friend1Idx - friend2Idx)-1;

            switch(op)
            {
                case '=':
                    if(gap != targetGap) return;
                    break;
                case '<':
                    if(gap >= targetGap) return;
                    break;
                case '>':
                    if(gap <= targetGap) return;
                    break;
            }
        }
        answer++;
        return;
    }

    // 순열 생성
    for(int i = 0; i < 8; i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        v[depth] = friends[i];

        DFS(depth+1, v, data, friends);
        mark[i] = false;
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    fill_n(mark, sizeof(mark)/sizeof(bool), false);
    char friends[8] = {'A','C','F','J','M','N','R','T'};
    vector<char> v(8, NULL);
    DFS(0, v, data, friends);

    return answer;
}