#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Node
{
    int idx = 0;
    int num = 0;
    Node* left = NULL;
    Node* right = NULL;
};

int N;
int answer = 0;
vector<Node> v(20);
// 현재 다음으로 방문 가능한 노드의 인덱스
//bool canVisit[20];

void Print(vector<bool> canVisit)
{
    cout << "CanVisit: ";
    for(int i = 0; i < N; i++)
    {
        if(canVisit[i]) cout << i << ' ';
    }
    cout << endl;
}

void dfs(Node* node, int sheep, int wolf, vector<bool> canVisit)
{
    if(node == NULL) return;
    if(node->num == 1 && wolf+1 >= sheep) {  return; }

    if(node->num == 0) sheep++;
    else wolf++;
    answer = max(answer, sheep);

    if(node->left != NULL) canVisit[node->left->idx] = true;
    if(node->right != NULL) canVisit[node->right->idx] = true;
    canVisit[node->idx] = false;

//    cout << node->idx << ' ' << sheep << ' ' << wolf << ' ' << endl;
//    Print(canVisit);
    for(int i = 0; i < N; i++)
    {
        if(!canVisit[i]) continue; // 방문 불가 노드
//        cout << "i: " << i << ' ' << "curNode: " << node->idx << endl;
        dfs(&v[i], sheep, wolf, canVisit);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    N = info.size();

    for(int i = 0; i < info.size(); i++)
    {
        Node node;
        node.idx = i;
        node.num = info[i];
        v[i] = node;
    }

    for(int i = 0; i < edges.size(); i++)
    {
        int parent = edges[i][0];
        int child = edges[i][1];
        if(v[parent].left == NULL) v[parent].left = &v[child];
        else v[parent].right = &v[child];
    }

    vector<bool> canVisit(info.size());
    // 루트의 좌측, 우측 자식 방문가능 처리
    if(v[0].left != NULL) canVisit[v[0].left->idx] = true;
    if(v[0].right != NULL) canVisit[v[0].right->idx] = true;

    dfs(&v[0], 0, 0, canVisit);
//    cout << answer;
    return answer;
}

int main()
{
    vector<int> info =
            {
                    0,0,1,1,1,0,1,0,1,0,1,1
            };
    vector<vector<int>> edges =
            {
                    {0,1}, {1,2}, {1,4}, {0,8}, {8,7}, {9,10},
                    {9,11}, {4,3}, {6,5}, {4,6}, {8,9}
            };
    solution(info, edges);

//    vector<int> info =
//            {
//                    0,1,0,1,1,0,1,0,0,1,0
//            };
//    vector<vector<int>> edges =
//            {
//                    {0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6},
//                    {3,7}, {4,8}, {6,9}, {9,10}
//            };
//    solution(info, edges);
}