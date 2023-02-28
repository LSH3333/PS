#include <iostream>
#include <cstring>
using namespace std;

int pre[1010];
int preIdx[1010];
int in[1010];
int inIdx[1010];

void Init() {
    memset(pre, 0, sizeof(pre));
    memset(preIdx, 0, sizeof(preIdx));
    memset(in, 0, sizeof(in));
    memset(inIdx, 0, sizeof(inIdx));
}

// in[] 의 idx
void Recur(int left, int mid, int right) {

    int root = in[mid];
    int leftCnt = mid - left;
    int rightCnt = right - mid;

    if(leftCnt > 0) {
        int leftChild = pre[preIdx[root] + 1];
        Recur(left, inIdx[leftChild], mid-1);
    }
    if(rightCnt > 0) {
        int rightChild = pre[preIdx[root] + leftCnt + 1];
        Recur(mid+1, inIdx[rightChild], right);
    }

    cout << root << ' ';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        Init();

        int N; cin >> N;
        // inorder
        for(int i = 0; i < N; i++) {
            cin >> pre[i];
            preIdx[pre[i]] = i;
        }
        // preorder
        for(int i = 0; i < N; i++) {
            cin >> in[i];
            inIdx[in[i]] = i;
        }

        Recur(0, inIdx[pre[0]], N-1);
        cout << '\n';
    }
}
