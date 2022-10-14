#include <iostream>
using namespace std;

bool d[31][40001];
int weight[35];
int N;

void dfs(int depth, int w)
{
    if(depth > N || d[depth][w]) return;
    d[depth][w] = true;
    dfs(depth+1, w + weight[depth]); // 추 올림
    dfs(depth+1, w); // 추 올리지 않음
    dfs(depth+1, abs(w - weight[depth])); // 구슬쪽에 추를 올리는 경우
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }

    dfs(0, 0);


    int M; cin >> M;
    for(int i = 0; i < M; i++)
    {
        int marble; cin >> marble;
        if(d[N][marble]) cout << "Y ";
        else cout << "N ";
    }
}