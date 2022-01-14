#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int num;
    int x, y;
    Node* left;
    Node* right;
};

bool cmp(const Node &a, const Node &b)
{
    if(a.y == b.y) return a.x < b.x;
    return a.y > b.y;
}

void MakeTree(Node *root, Node *child)
{
    // left child
    if(child->x < root->x)
    {
        // 현재 기준 루트의 left child가 아직 없으면 할당 후 리턴
        if(root->left == NULL)
        {
            root->left = child;
            return;
        }
        // 이미 있다면 기준 루트 변경
        MakeTree(root->left, child);
    }
    // right child
    else
    {
        if(root->right == NULL)
        {
            root->right = child;
            return;
        }
        MakeTree(root->right, child);
    }
}

// parent, left, right
vector<int> preorder;
void PreOrder(Node *root)
{
    if(root == NULL) return;

    preorder.push_back(root->num);
    PreOrder(root->left);
    PreOrder(root->right);
}

// left, right , parent
vector<int> postorder;
void PostOrder(Node *root)
{
    if(root == NULL) return;

    PostOrder(root->left);
    PostOrder(root->right);
    postorder.push_back(root->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> nodes;

    for(int i = 0; i < nodeinfo.size(); i++)
    {
        Node node;
        node.num = i+1;
        node.x = nodeinfo[i][0];
        node.y = nodeinfo[i][1];
        node.left = NULL;
        node.right = NULL;
        nodes.push_back(node);
    }
    sort(nodes.begin(), nodes.end(), cmp);

    for(int i = 1; i < nodes.size(); i++) MakeTree(&nodes[0], &nodes[i]);

    PreOrder(&nodes[0]);
//    cout << endl << "pre: " << endl;
//    for(auto x : preorder) cout << x << ' '; cout << endl;

    PostOrder(&nodes[0]);
//    cout << endl << "post: " << endl;
//    for(auto x : postorder) cout << x << ' '; cout << endl;

    answer.push_back(preorder);
    answer.push_back(postorder);
    return answer;
}
