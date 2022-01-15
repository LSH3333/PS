#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int num;
    int x;
    int y;
    Node* left_child;
    Node* right_child;
};

bool cmp(const Node &a, const Node &b)
{
    if(a.y == b.y)
    {
        return a.x < b.x;
    }
    return a.y > b.y;
}

void BuildBinaryTree(Node* parent, Node* child)
{
    // left child
    if(child->x < parent->x)
    {
        if(parent->left_child == NULL)
        {
            parent->left_child = child;
            return;
        }
        BuildBinaryTree(parent->left_child, child);
    }
    // right child
    else
    {
        if(parent->right_child == NULL)
        {
            parent->right_child = child;
            return;
        }
        BuildBinaryTree(parent->right_child, child);
    }
}

void PreOrder(Node* parent, vector<int> &preorder)
{
    if(parent == NULL) return;
    preorder.push_back(parent->num);
    PreOrder(parent->left_child, preorder);
    PreOrder(parent->right_child, preorder);
}

void PostOrder(Node* parent, vector<int> &postorder)
{
    if(parent == NULL) return;
    PostOrder(parent->left_child, postorder);
    PostOrder(parent->right_child, postorder);
    postorder.push_back(parent->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    vector<Node> v;
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        Node node;
        node.num = i+1;
        node.x = nodeinfo[i][0];
        node.y = nodeinfo[i][1];
        node.left_child = NULL;
        node.right_child = NULL;
        v.push_back(node);
    }
    sort(v.begin(), v.end(), cmp);

    for(int i = 1; i < v.size(); i++) BuildBinaryTree(&v[0], &v[i]);

    vector<int> preorder;
    PreOrder(&v[0], preorder);
    vector<int> postorder;
    PostOrder(&v[0], postorder);

    answer.push_back(preorder);
    answer.push_back(postorder);

    return answer;
}