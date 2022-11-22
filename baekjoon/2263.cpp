#include <iostream>
using namespace std;

int N;
int in[100010];
int post[100010];
int root[100010];

void MakeTree(int in_l, int in_r, int post_l, int post_r) {
    if(in_l > in_r || post_l > post_r) return;
    int r = post[post_r];
    cout << r << ' ';
    // left child
    MakeTree(in_l, root[r]-1, post_l, post_l + (root[r]-in_l)-1);
    // right child
    MakeTree(root[r]+1, in_r, post_l+(root[r]-in_l), post_r-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> in[i];
        root[in[i]] = i;
    }
    for(int i = 0; i < N; i++) {
        cin >> post[i];
    }

    MakeTree(0, N-1, 0, N-1);
}