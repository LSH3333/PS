#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Cal(char target)
{
    int up = target - 'A';
    int down = 'Z' - target + 1;

    return min(up,down);
}

int solution(string name) {
    int answer = 0;
    int cur = 0;
    string AA(name.size(), 'A');

    answer += Cal(name[cur]);
    AA[cur] = name[cur];
    if(AA == name) return answer;

    while(true)
    {
        for(int i = 1; i < name.size(); i++)
        {
            // left cur
            int leftCur = cur - (i % name.size());
            if(leftCur < 0) leftCur += name.size();

            // right cur
            int rightCur = (cur + i) % name.size();

            // left, right 중 가까운쪽으로 이동
            if(AA[rightCur] != name[rightCur])
            {
                answer += i;
                answer += Cal(name[rightCur]);
                cur = rightCur;
                AA[rightCur] = name[rightCur];
                break;
            }
            else if(AA[leftCur] != name[leftCur])
            {
                answer += i;
                answer += Cal(name[leftCur]);
                cur = leftCur;
                AA[leftCur] = name[leftCur];
                break;
            }
        }
        if(AA == name) break;
    }

    return answer;
}