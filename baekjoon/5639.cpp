#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node *right;
};

void MakeTree(Node *parent, Node *child)
{
    // left
    if(parent->val > child->val)
    {
        if(parent->left == nullptr) parent->left = child;
        else MakeTree(parent->left, child);
    }
    else // right
    {
        if(parent->right == nullptr) parent->right = child;
        else MakeTree(parent->right, child);
    }
}


void PostOrder(vector<int> &post, Node *node)
{
    if(node == nullptr) return;
    PostOrder(post, node->left);
    PostOrder(post, node->right);
    post.push_back(node->val);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<Node> nodes;
    int n;
    while(cin >> n)
    {
        nodes.push_back({n, nullptr, nullptr});
    }

    for(int i = 1; i < nodes.size(); i++) MakeTree(&nodes[0], &nodes[i]);

    vector<int> post;
    PostOrder(post, &nodes[0]);

    for(auto x : post) cout << x << '\n';
}