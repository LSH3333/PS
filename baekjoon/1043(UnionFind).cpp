#include <iostream>
#include <vector>
using namespace std;

int parent[51];
vector<int> party[51];
vector<int> knows;

int FindParent(int n)
{
    if(parent[n] == n) return n;
    return parent[n] = FindParent(parent[n]);
}

void Union(int n1, int n2)
{
    n1 = FindParent(n1);
    n2 = FindParent(n2);
    parent[n2] = n1;
}

// 진실을 아는 사람과 같은 부모라면 return false
bool CheckParent(int target)
{
    for(auto x : knows)
    {
        if(FindParent(target) == FindParent(x)) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) parent[i] = i;
    int num; cin >> num;
    for(int i = 0; i < num; i++) { int n; cin >> n; knows.push_back(n);}
    for(int i = 0; i < M; i++)
    {
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            int n; cin >> n;
            party[i].push_back(n);
        }
    }

    // Union
    for(int i = 0; i < M; i++)
    {
        int target = party[i][0];
        for(int j = 1; j < party[i].size(); j++)
        {
            Union(target, party[i][j]);
        }
    }


    int answer = 0;
    for(int i = 0; i < M; i++)
    {
        bool someoneKnows = false;
        for(int j = 0; j < party[i].size(); j++)
        {
            int target = party[i][j];
            if(!CheckParent(target)) {someoneKnows = true; break;}
        }
        if(!someoneKnows) answer++;
    }
    cout << answer;
}