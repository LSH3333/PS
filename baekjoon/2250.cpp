#include <iostream>
#include <vector>
using namespace std;

int N;

struct Node
{
    Node *left;
    Node *right;
};

Node nodePool[10010];
int mark[10010];
int parentNum[10010];
int colIdx = 1;

void InOrder(Node *node, int level)
{
    if(node == nullptr) return;

    InOrder(node->left, level+1);
    mark[colIdx++] = level;
    InOrder(node->right, level+1);
}

int FindRoot()
{
    for(int i = 1; i <= N; i++)
    {
        if(parentNum[i] == 0) return i;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        Node *left, *right;
        if(b != -1) left = &nodePool[b];
        else left = nullptr;
        if(c != -1) right = &nodePool[c];
        else right = nullptr;

        nodePool[a] = {left, right};

        parentNum[b]++;
        parentNum[c]++;
    }

    int root = FindRoot();
    InOrder(&nodePool[root], 1);

    // col min, max
    pair<int,int> levelMark[10010];
    int maxLevel = 0;
    for(int i = 1; i <= N; i++)
    {
        levelMark[i] = {20000, 0};
        maxLevel = max(maxLevel, mark[i]);
    }

    for(int col = 1; col <= N; col++)
    {
        int level = mark[col];
        int minCol = min(levelMark[level].first, col);
        int maxCol = max(levelMark[level].second, col);
        levelMark[level] = {minCol, maxCol};
    }

    int ansWidth = levelMark[1].second - levelMark[1].first + 1;
    int ansLevel = 1;
    for(int i = 1; i <= maxLevel; i++)
    {
        int width = levelMark[i].second - levelMark[i].first + 1;
        if(width > ansWidth)
        {
            ansWidth = width;
            ansLevel = i;
        }
    }
    cout << ansLevel << ' ' << ansWidth;
}