#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> party[51];
bool knows[51]; // 진실을 아는 사람
bool mark[51]; // 말할수 없는 파티

int main()
{
    queue<int> q;
    int N, M; cin >> N >> M;
    int num; cin >> num;
    for(int i = 0; i < num; i++)
    {
        int n; cin >> n; q.push(n);
        knows[n] = true;
    }
    for(int i = 0; i < M; i++)
    {
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            int n; cin >> n;
            party[i].push_back(n);
        }
    }


    while(!q.empty())
    {
        int cur = q.front(); q.pop();

        for(int i = 0; i < M; i++)
        {
            if(mark[i]) continue; // 말할수 없는 파티
            for(int j = 0; j < party[i].size(); j++)
            {
                int target = party[i][j];
                if(target == cur) // 진실 아는 사람이 있는 파티임
                {
                    mark[i] = true; // i 파티가 진실을 아는 파티임을 기록
                    for(int k = 0; k < party[i].size(); k++)
                    {
                        target = party[i][k];
                        if(!knows[target])
                        {
                            q.push(target); // 진실을 아는 사람 기록
                            knows[target] = true;
                        }
                    }
                }
            }
        }

    }

    int answer = 0;
    for(int i = 0; i < M; i++) if(!mark[i]) answer++;
    cout << answer;
}