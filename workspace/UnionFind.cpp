// Union-Find Algorithm 

#include <iostream>
#include <vector>
using namespace std;

// 노드의 부모를 재귀적으로 찾는다 (가장 위의 루트가 몇번 노드인가?)
int getParent(vector<int> &parent, int x)
{
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

// Union
// 두 노드를 잇는다
void unionParent(vector<int> &parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    // 더 작은 노드를 부모로
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

// Find
// 두 노드 a와 b가 그래프상 이어져있는지 탐색한다
// 이어져있다면 true, 아니라면 false 리턴
bool findParent(vector<int> &parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return true;
    else return false;
}


int main()
{
    // 최초에 각 노드는 자기 자신이 부모이다
    vector<int> parent(11);
    for(int i = 1; i <= 10; i++)
        parent[i] = i;

    // 노드들을 잇는다
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    // 노드 1과 5가 그래프상 서로 이어져있는가?
    cout << findParent(parent, 1, 5) << endl;
    unionParent(parent, 1, 5);
    cout << findParent(parent, 1, 5) << endl;
}