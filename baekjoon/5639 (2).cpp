#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
};


// preOrder : root->left->right
void MakeTree(vector<Node> &nodes, Node *node, Node *parent) {
    if (node->val < parent->val) {
        if(parent->left == NULL) {
            parent->left = node;
            return;
        }
        MakeTree(nodes, node, parent->left);
    } else if (node->val > parent->val) {
        if(parent->right == NULL) {
            parent->right = node;
            return;
        }
        MakeTree(nodes, node, parent->right);
    }
}

// left->right->root
void PostOrder(vector<int> &post, Node *parent) {
    if(parent == NULL) return;
    PostOrder(post, parent->left);
    PostOrder(post, parent->right);
    post.push_back(parent->val);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<Node> nodes;
    while(cin >> n) {
        nodes.push_back({n, NULL, NULL});
    }

    for(int i = 1; i < nodes.size(); i++) {
        MakeTree(nodes, &nodes[i], &nodes[0]);
    }


    vector<int> post;
    PostOrder(post, &nodes[0]);

    for(auto node : post) {
        cout << node << '\n';
    }
}