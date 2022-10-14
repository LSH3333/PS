#include <iostream>
#include <vector>
using namespace std;

vector<char> pre, in, post;

struct tree
{
    char node;
    tree* LChild;
    tree* RChild;
};

void PreOrder(tree* root)
{
    if(root == NULL) return;
    pre.push_back(root->node);
    PreOrder(root->LChild);
    PreOrder(root->RChild);
}

void PostOrder(tree* root)
{
    if(root == NULL) return;
    PostOrder(root->LChild);
    PostOrder(root->RChild);
    post.push_back(root->node);
}

void InOrder(tree* root)
{
    if(root == NULL) return;
    InOrder(root->LChild);
    in.push_back(root->node);
    InOrder(root->RChild);
}

int main()
{
    vector<tree> v;
    for(int i = (int)'A'; i <= (int)'Z'; i++)
    {
        v.push_back({(char)i, NULL, NULL});
    }

    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        char node, l, r;
        cin >> node >> l >> r;
        if(l != '.') v[node-'A'].LChild = &v[l-'A'];
        if(r != '.') v[node-'A'].RChild = &v[r-'A'];
    }

//    for(auto x : v)
//    {
//        cout << x.node << endl;
//        if(x.LChild != NULL) cout << x.LChild->node << endl;
//        else cout << '.' << endl;
//        if(x.RChild != NULL) cout << x.RChild->node << endl;
//        else cout << '.' << endl;
//        cout << endl;
//    }

    PreOrder(&v['A'-'A']);
    PostOrder(&v['A'-'A']);
    InOrder(&v['A'-'A']);

    for(auto x : pre) cout << x; cout << '\n';
    for(auto x : in) cout << x; cout << '\n';
    for(auto x : post) cout << x; 
}