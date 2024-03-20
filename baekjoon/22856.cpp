#include <iostream>
#include <vector>

using namespace std;

int N;

struct Node {
    Node *left;
    Node *right;
    int num;
};

int answer;
int lastNode;
int visitedNodeCnt;
bool visited[100010];
Node nodePool[100010];
bool finished;

void InOrder(Node *node) {
    answer++;

    if (node->left != nullptr) {
        InOrder(node->left);
        if (!finished) {
            answer++;
        }
    }
    if (node->num == lastNode) {
        finished = true;
    }
    if (node->right != nullptr) {
        InOrder(node->right);
        if (!finished) {
            answer++;
        }
    }
}

void FindLastNode(Node *node) {
    if (node == nullptr) return;

    FindLastNode(node->left);
    if (visitedNodeCnt == N - 1) {
        lastNode = node->num;
    }
    if (!visited[node->num]) {
        visited[node->num] = true;
        visitedNodeCnt++;
    }
    FindLastNode(node->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Node *left = nullptr, *right = nullptr;
        if (b != -1) {
            left = &nodePool[b];
        }
        if (c != -1) {
            right = &nodePool[c];
        }
        nodePool[a] = {left, right, a};
    }

    FindLastNode(&nodePool[1]);


    InOrder(&nodePool[1]);

    cout << answer-1;
}