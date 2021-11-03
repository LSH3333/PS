#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ans = 0;

vector<int> marble;

int energy;


void Input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        marble.push_back(w);
    }
}

void dfs()
{
    // 양쪽끝 구슬 두개는 제거할수 없으므로 벡터 marble의 크기가 2가 되면 모든 구슬을 뽑았다
    if(marble.size() == 2)
    {
        // energy 최댓값 갱신
        ans = max(ans, energy);
        return;
    }

    // 양쪽끝 구슬은 제거 불가능하므로 1부터 marble.size()-2 까지
    for(int i = 1; i < marble.size()-1; i++)
    {
        // 다시 marble 벡터에 삽입하기 위해 기억해 놓는다
        int selected = marble[i];

        // 양쪽 구슬 에너지 계산
        energy += marble[i-1] * marble[i+1];
        // 구슬 제거
        marble.erase(marble.begin()+i);

        dfs();

        // 뽑은 구슬다시 벡터에 넣어서 복원
        marble.insert(marble.begin()+i, selected);
        // 더한 에너지 빼서 복원함
        energy -= marble[i-1] * marble[i+1];
    }
}

int main()
{
    Input();

    dfs();

    cout << ans;
}