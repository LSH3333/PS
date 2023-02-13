#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

struct Node {
    string food;
    vector<Node*> child;
};

Node nodePool[10000];
int poolIdx = 1;

void MakeNode(const string &food, Node *root) {
    Node node;
    node.food = food;
    nodePool[poolIdx++] = node;
    root->child.push_back(&nodePool[poolIdx-1]);
}

void MakeTree(Node *root, int depth, const vector<string> &foods) {
    if(depth == foods.size()){
        return;
    }

    bool found = false;
    for (auto x: root->child) {
        if (x->food == foods[depth]) {
            MakeTree(x, depth + 1, foods);
            found = true;
            break;
        }
    }

    if(!found) {
        MakeNode(foods[depth], root);
        MakeTree(root->child.back(), depth + 1, foods);
    }
}

void PrintTree(Node *root, int depth) {

    if(depth > 0) {
        string floor;
        for(int i = 0; i < depth-1; i++) {
            floor += "--";
        }
        cout << floor << root->food << '\n';
    }

    for (auto x: root->child) {
        PrintTree(x, depth+1);
    }
}

bool cmp(Node *a,Node *b) {
    return a->food < b->food;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    nodePool[0].food = "ROOT";
    cin >> N;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        vector<string> foods(n);
        for(int j = 0; j < n; j++) {
            cin >> foods[j];
        }

        MakeTree(&nodePool[0], 0, foods);
    }

    for(int i = 0; i < poolIdx; i++) {
        sort(nodePool[i].child.begin(), nodePool[i].child.end(), cmp);
    }


    PrintTree(&nodePool[0], 0);



}