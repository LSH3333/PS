#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 100000000
#define MAX 210
using namespace std;

vector<pair<int,int>> v[MAX];

void MakeGraph(vector<vector<int>> fares)
{
    for(int i = 0; i < fares.size(); i++)
    {
        int start = fares[i][0];
        int end = fares[i][1];
        int cost = fares[i][2];

        v[start].push_back({end,cost});
        v[end].push_back({start,cost});
    }
}

void Dijkstra(int start, vector<int> &d)
{
    d[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({start,0});

    while(!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if(d[current] < distance) continue;

        for(int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int nextDistance = distance + v[current][i].second;

            if(nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push({next, -nextDistance});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    answer = 1000000000;
    MakeGraph(fares);

    // 합승비용
    vector<int> S(n+1, INF);
    Dijkstra(s, S);
    // A에서 모든 정점까지 최단비용
    vector<int> A(n+1, INF);
    Dijkstra(a,A);
    // B에서 모든 정점까지 최단비용
    vector<int> B(n+1, INF);
    Dijkstra(b,B);

//    for(auto i : v)
//    {
//        for(auto y : i)
//        {
//            cout << y.first << "," << y.second << ' ';
//        }cout << endl;
//    }cout << endl;
//    for(int i = 1; i <= n; i++)
//    {
//        cout << S[i] << ' ';
//    } cout << endl;
//    cout << endl;

    for(int i = 1; i <= n; i++)
    {
        int togetherCost = S[i];
        int ACost = A[i];
        int BCost = B[i];
        int total = togetherCost + ACost + BCost;

        answer = min(answer, total);
    }

    return answer;
}

int main()
{
    int n = 7,s=3,a=4,b=1;
    vector<vector<int>> fares = {{5,7,9},{4,6,4},{3,6,1},{3,2,3},{2,1,6}};
//    int n = 6, s=4,a=5,b=6;
//    vector<vector<int>> fares = {{2,6,6},{6,3,7},{4,6,7},{6,5,11},{2,5,12},{5,3,20},{2,4,8},{4,3,9}};;
    solution(n,s,a,b,fares);
}