#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int val;
    int x;
    int y;
    Node* left;
    Node* right;
};

bool cmp(const Node &a, const Node &b)
{
    return a.y > b.y;
}

void MakeTree(Node* parent, Node* child)
{
    // left
    if(child->x < parent->x)
    {
        if(parent->left == NULL) parent->left = child;
        else MakeTree(parent->left, child);
    }
        // right
    else if(child->x > parent->x)
    {
        if(parent->right == NULL) parent->right = child;
        else MakeTree(parent->right, child);
    }
}

vector<int> pre;
void PreOrder(Node* node)
{
    if(node == NULL) return;
    pre.push_back(node->val);
    PreOrder(node->left);
    PreOrder(node->right);
}

vector<int> post;
void PostOrder(Node* node)
{
    if(node == NULL) return;
    PostOrder(node->left);
    PostOrder(node->right);
    post.push_back(node->val);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    vector<Node> nodes;
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        Node node;
        node.val = i+1;
        node.x = nodeinfo[i][0];
        node.y = nodeinfo[i][1];
        node.left = NULL;
        node.right = NULL;
        nodes.push_back(node);
    }

    sort(nodes.begin(), nodes.end(), cmp);

    for(int i = 1; i < nodes.size(); i++) MakeTree(&nodes[0], &nodes[i]);

//    for(auto x : nodes)
//    {
//        cout << "node: " << x.x << ' ' << x.y << ' ' << x.val << endl;
//        if(x.left != NULL) cout << "left: " << x.left->x << ' ' << x.left->y << endl;
//        if(x.right != NULL) cout << "right: " << x.right->x << ' ' << x.right->y << endl;
//        cout << endl;
//    }

    PreOrder(&nodes[0]);
    PostOrder(&nodes[0]);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}
