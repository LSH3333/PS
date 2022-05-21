#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int board[11][11];
int parentNode[10];
int N, M;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfsIsland(int _r, int _c, int num, vector<vector<bool>> &visited)
{
    queue<pair<int,int>> q;
    q.push({_r, _c});
    visited[_r][_c] = true;
    board[_r][_c] = num;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] == 0 || visited[nr][nc]) continue;
            board[nr][nc] = num;
            visited[nr][nc] = true;
            q.push({nr,nc});
        }
    }
}

// 각 섬들 넘버링, 섬들의 갯수 리턴
int FindIslands()
{
    vector<vector<bool>> visited(11, vector<bool>(11, false));
    int num = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == 0 || visited[i][j]) continue;
            bfsIsland(i, j, num, visited);
            num++;
        }
    }
    return num-1;
}
////////

// island 부터 island 보다 높은 숫자의 섬들까지의 최단 경로 탐색
void FindShortestPath(int island, int paths[][11])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] != island) continue;

            for(int dir = 0; dir < 4; dir++)
            {
                int r = i; int c = j;
                int cost = 0;
                // 하나의 방향으로 쭉 가본다
                while(true)
                {
                    int nr = r + dr[dir];
                    int nc = c + dc[dir];

                    if(nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == island) break;
                    if(board[nr][nc] == 0) { r = nr; c = nc; cost++; } // 한칸 이동
                    else if(board[nr][nc] != island) // 다음 섬 찾음
                    {
                        if(cost >= 2) paths[island][board[nr][nc]] = min(paths[island][board[nr][nc]], cost);
                        break;
                    }
                }
            }
        }
    }
}

// 가중치 기준 오름차순 정렬
bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

//////// kruskal
int FindParentNode(int node)
{
    if(node == parentNode[node]) return node;
    return parentNode[node] = FindParentNode(parentNode[node]);
}

bool IsParentSame(int node1, int node2)
{
    if(FindParentNode(node1) == FindParentNode(node2)) return true;
    return false;
}

void Union(int node1, int node2)
{
    node1 = FindParentNode(node1);
    node2 = FindParentNode(node2);
//    cout << "node1, node2: " << node1 << ' ' << node2 << endl;
    if(node1 < node2) parentNode[node2] = node1;
    else parentNode[node1] = node2;
}

void Print()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << board[i][j] << ' ';
        }cout<<endl;
    }cout<<endl;
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    // 각 섬들 넘버링
    int islandsNum = FindIslands();
    // r에서 c까지 최단 경로
    int paths[11][11];
    for(int i = 0; i < 11; i++)
        for(int j = 0; j < 11; j++) paths[i][j] = 999;

    // 각 섬 마다 자기보다 큰 넘버의 섬까지의 최단 거리 구함
    for(int island = 1; island < islandsNum; island++)
    {
        FindShortestPath(island, paths);
    }

//    Print();

    // {a,b,c} = a섬에서 b섬까지의 최단 경로는 c
    vector<vector<int>> costs;
    for(int i = 1; i <= islandsNum; i++)
    {
        for(int j = 1; j <= islandsNum; j++)
        {
            if(paths[i][j] == 999) continue;
            costs.push_back({i, j, paths[i][j]});
        }
    }

    // kruskal로 mst 구함
    int answer = 0;
    // 가중치 기준 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);
    for(int i = 0; i < 10; i++) parentNode[i] = i;



    int bridgeNum = 0;
    for(auto x : costs)
    {
        if(!IsParentSame(x[0], x[1]))
        {
            bridgeNum++;
            answer += x[2];
            Union(x[0], x[1]);
        }
    }

    for(auto x : costs)
    {
        for(auto y : x) cout<<y<<' ';cout<<endl;
    }
    for(int i = 1; i <= islandsNum; i++) cout << parentNode[i] << ' '; cout << endl;

    // 다리의 갯수가 섬의 갯수보다 하나 작아야 모두 연결된것
    if(islandsNum-1 == bridgeNum) cout << answer;
    else cout << -1;
}