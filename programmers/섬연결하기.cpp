#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int parentNode[101];

bool cmd(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

// 루트에 있는 부모 노드를 재귀적으로 찾는다
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
    parentNode[node2] = node1;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmd);

    for(int i = 0; i < 100; i++) parentNode[i] = i;

    for(auto x : costs)
    {
        // 부모 노드가 다르다면 사이클 형성하지 않음
        if(!IsParentSame(x[0], x[1]))
        {
            answer += x[2]; // 가중치 더함
            Union(x[0], x[1]);
        }
    }
    
    return answer;
}