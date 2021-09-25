#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// false: 중요도 높은게 큐에 존재
bool FindPriority(int mark[], int num)
{
    for(int i = num+1; i < 10; i++)
    {
        if(mark[i] > 0) return false;
    }
    return true;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int,int>> q;
    int mark[10] = {0,};
    for(int i = 0; i < priorities.size(); i++)
    {
        if(i == location)
        {
            q.push({priorities[i], 1});
        }
        else
        {
            q.push({priorities[i], 0});
        }
        mark[priorities[i]]++;
    }

    while(true)
    {
        // 큐의 front보다 중요도 높은게 아직 큐에 존재
        if(!FindPriority(mark, q.front().first))
        {
            q.push({q.front().first,q.front().second});
            q.pop();
        }
            // 큐의 front가 가장 중요도 높은 문서임
        else
        {
            if(q.front().second == 1) break;
            mark[q.front().first]--;
            q.pop();
            answer++;
        }
    }

    return answer+1;
}
