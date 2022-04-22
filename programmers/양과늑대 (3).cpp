#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> e(20);
vector<int> _info;
int N;
int answer;

void dfs(int sheep, int wolf, vector<bool> &mark)
{
    answer = max(answer, sheep);

    vector<int> canVisit;
    // 방문 가능 노드 탐색
    for(int i = 0; i < N; i++)
    {
        if(!mark[i]) continue;
        for(auto x : e[i])
        {
            if(!mark[x]) canVisit.push_back(x);
        }
//        int n1 = e[i][0]; int n2 = e[i][1];
//        if(!mark[n1]) canVisit.push_back(n1);
//        if(!mark[n2]) canVisit.push_back(n2);
    }

    // print
//    cout << "cur: " << endl;
//    for(auto x : mark) cout << x << ' '; cout << endl;
//    cout << "canVisit: " << endl;
//    for(auto x : canVisit) cout << x << ' '; cout << endl << endl;

    for(auto nextNode : canVisit)
    {
        // next node가 늑대고 이동한다면 늑대가 양 잡아먹을수 있음
        if(_info[nextNode] == 1 && wolf+1 >= sheep) continue;

        mark[nextNode] = true;
        if(_info[nextNode] == 0) dfs(sheep+1, wolf, mark);
        else dfs(sheep, wolf+1, mark);
        mark[nextNode] = false;
    }
}

int solution(vector<int> info, vector<vector<int>> edges)
{
    N = info.size();
    _info = info;
    for(int i = 0; i < edges.size(); i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        e[from].push_back(to);
    }
    vector<bool> mark(20, false);
    mark[0] = true;
    dfs(1, 0, mark);

//    cout << answer;
    return answer;
}

int main()
{
    vector<int> info = {0,1,0,1,1,0,1,0,0,1,0};
    vector<vector<int>> edges =
            {
                    {0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}, {3,7},
                    {4,8}, {6,9}, {9,10}
            };
    solution(info, edges);
}