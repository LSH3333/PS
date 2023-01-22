#include <iostream>
using namespace std;

int N, M, K;
long long segmentTree[4000010];
long long arr[4000010];


long long initSegmentTree(int start, int end, int node) {
    if(start == end) return segmentTree[node] = arr[start];

    int mid = (start + end) / 2;
    return segmentTree[node] = initSegmentTree(start, mid, node * 2) +
            initSegmentTree(mid+1, end, node*2+1);
}

// left 부터 right 까지 범위의 합 구함
long long getSum(int start, int end, int node, int left, int right) {
    // 찾는 구간이 노드의 범위 벗어난 경우
    if(left > end || right < start) return 0;
    // 노드의 범위가 찾는 구간 내에 포함될 경우
    if(left <= start && end <= right) return segmentTree[node];

    int mid = (start + end) / 2;
    return getSum(start, mid, node*2, left, right) + getSum(mid+1, end, node*2+1, left, right);
}

// 배열의 idx 번째 원소를 diff 만큼 수정
// start <= idx <= end 인 노드인 경우만 수정
void updateTree(int start, int end, int node, int idx, long long diff) {
    if(idx < start || end < idx) return;
    segmentTree[node] += diff;
    if(start == end) return;

    int mid = (start + end) / 2;
    updateTree(start, mid, node * 2, idx, diff);
    updateTree(mid + 1, end, node * 2 + 1, idx, diff);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    // Segment Tree 생성
    initSegmentTree(1, N, 1);

    for(int i = 0; i < M+K; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        // b번째 수를 c로 수정
        if(a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            updateTree(1, N, 1, b, diff);
        }
        // b번째 부터 c번째 까지 합 구함
        else {
            cout << getSum(1, N, 1, b, c) << '\n';
        }
    }

}