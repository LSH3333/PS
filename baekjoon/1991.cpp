#include <iostream>
#include <vector>
using namespace std;

int N;
vector<char> pre,in,post;

struct tree {
    char node;
    tree *LChild;
    tree *RChild;
};

void PreOrder(tree *root) {
    if(root == NULL) return;
    pre.push_back(root->node);
    PreOrder(root->LChild);
    PreOrder(root->RChild);
}

void InOrder(tree *root) {
    if(root == NULL) return;
    InOrder(root->LChild);
    in.push_back(root->node);
    InOrder(root->RChild);
}

void PostOrder(tree *root) {
    if(root == NULL) return;
    PostOrder(root->LChild);
    PostOrder(root->RChild);
    post.push_back(root->node);
}

int main() {
    vector<tree> v;
    for(char i = 'A'; i <= 'Z'; i++) {
        v.push_back({i, NULL, NULL});
    }

    cin >> N;
    for(int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;

        if(left != '.') {
            v[(int)(parent-'A')].LChild = &v[(int)(left-'A')];
        }
        if(right != '.') {
            v[(int)(parent-'A')].RChild = &v[(int)(right-'A')];
        }
    }

    PreOrder(&v[0]);
    InOrder(&v[0]);
    PostOrder(&v[0]);

    for(auto x : pre) cout << x; cout << '\n';
    for(auto x : in) cout << x; cout << '\n';
    for(auto x : post) cout << x; cout << '\n';

}