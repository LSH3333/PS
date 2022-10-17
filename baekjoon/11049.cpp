#include <iostream>
#include <vector>
using namespace std;

int N;
pair<int,int> arr[510];
bool visited[510];
int answer = 2100000000;

void dfs(vector<int> &v, int depth, int sum)
{
    if(depth == N-1)
    {
        answer = min(answer, sum);
        return;
    }

    for(int i = 0; i < N-1; i++)
    {
        if(visited[i]) continue;

        visited[i] = true;
        v.push_back(i);
        pair<int,int> tmp1 = arr[i], tmp2 = arr[i+1];
        int add = (arr[i].first * arr[i].second * arr[i+1].second);
        arr[i] = {arr[i].first, arr[i+1].second};
        arr[i+1] = arr[i];

        dfs(v, depth+1, sum + add);

        arr[i] = tmp1;
        arr[i+1] = tmp2;
        v.pop_back();
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> v;
    dfs(v, 0, 0);
    cout << answer;
}