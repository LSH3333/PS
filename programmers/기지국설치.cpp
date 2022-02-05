#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    queue<int> q;
    for(auto x : stations) q.push(x);

    int bound = w * 2 + 1;
    int idx = 1;
    while(idx <= n)
    {
        // q가 비어있지 않을때
        if(!q.empty())
        {
            if(idx < q.front()-w)
            {
                answer++;
                idx += bound;
            }
            else
            {
                idx = q.front() + w + 1;
                q.pop();
            }
        }
        // q를 모두 비웠을때
        else
        {
            if((n-idx+1) % bound != 0) answer++;
            answer += (n - idx + 1) / bound;
            break;
        }
    }
//    cout << answer;
    return answer;
}

int main()
{
//    vector<int> stations = {9};
//    solution(16, stations, 2);

    vector<int> stations = {4,11};
    solution(11, stations, 1);
}