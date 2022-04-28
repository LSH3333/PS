#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] > b[1];
}


class Node
{
public:
    int x;
    int y;
    int num;
    Node *left = nullptr;
    Node *right = nullptr;
};

void MakeTree(Node *n, Node *root)
{

    if(n->x < root->x)
    {
        if(root->left == nullptr)
        {
            root->left = new Node{n->x, n->y, n->num, nullptr, nullptr};
            return;
        }
        else MakeTree(n, root->left);
    }
    else
    {
        if(root->right == nullptr)
        {
            root->right = new Node{n->x, n->y, n->num, nullptr, nullptr};
            return;
        }
        else MakeTree(n, root->right);
    }
}

// root, left, right
vector<int> pre;
void PreOrder(Node *root)
{
    if(root == nullptr) return;
    pre.push_back(root->num);
    PreOrder(root->left);
    PreOrder(root->right);
}

// left, right, root
vector<int> post;
void PostOrder(Node *root)
{
    if(root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    post.push_back(root->num);
}

void Print(Node *root)
{
    if(root == nullptr) return;
    cout << root->num << endl;
    Print(root->left);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    for(int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i+1);

    sort(nodeinfo.begin(), nodeinfo.end(), cmp);

    Node *root = new Node{nodeinfo[0][0], nodeinfo[0][1], nodeinfo[0][2], nullptr, nullptr};

    for(int i = 1; i < nodeinfo.size(); i++)
    {
        Node *n = new Node{nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2], nullptr, nullptr};
        MakeTree(n, root);
    }

    PreOrder(root);
    PostOrder(root);
    
    vector<vector<int>> answer;
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo =
            {
                {5,3},{11,5},{13,3},{3,5},
                {6,1},{1,3},{8,6},{7,2},{2,2}

            };
    solution(nodeinfo);
}