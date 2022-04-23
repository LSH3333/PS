#include <iostream>
#include <algorithm>
#include <vector>
#define INF 20000000
using namespace std;

int arr[201][201];
int d[201][201];

void InitArr()
{
    for(int i = 0; i < 201; i++)
    {
        for(int j = 0; j < 201; j++)
        {
            if(i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
}

void floydWarshall(int number)
{
    for(int i = 1; i <= number; i++)
    {
        for(int j = 1; j <= number; j++)
        {
            d[i][j] = arr[i][j];
        }
    }

    // k = 거쳐가는 노드
    for(int k = 1; k <= number; k++)
    {
        // i = 출발 노드
        for(int i = 1; i <= number; i++)
        {
            // j = 도착 노드
            for(int j = 1; j <= number; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

//    for(int i = 1; i <= number; i++)
//    {
//        for(int j = 1; j <= number; j++)
//        {
//            cout << d[i][j] << ' ';
//        }
//        cout << endl;
//    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    InitArr();
    for(auto x : fares)
    {
        int from = x[0];
        int to = x[1];
        int cost = x[2];
        arr[from][to] = cost;
        arr[to][from] = cost;
    }

    floydWarshall(n);

    int answer = 2000000000;
    for(int i = 1; i <= n; i++)
    {
        int togetherCost = d[s][i];
        int aCost = d[i][a];
        int bCost = d[i][b];
        answer = min(answer, togetherCost+aCost+bCost);
    }

//    cout << answer;
    return answer;
}

int main()
{
//    vector<vector<int>> fares =
//            {
//                    {4,1,10}, {3,5,24}, {5,6,2}, {3,1,41}, {5,1,24}, {4,6,50}, {2,4,66},
//                    {2,3,22}, {1,6,25}
//            };

    vector<vector<int>> fares =
            {
                {5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}
            };
    solution(7,3,4,1,fares);
}