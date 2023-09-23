#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int parent[51];

int FindParent(int n) {
    if(parent[n] == n) {
        return n;
    }
    return parent[n] = FindParent(parent[n]);
}

bool IsParentSame(int n1, int n2) {
    return FindParent(n1) == FindParent(n2);
}

void Union(int n1, int n2) {
    n1 = FindParent(n1);
    n2 = FindParent(n2);
    parent[max(n1, n2)] = min(n1, n2);
}

int MakeMST(const vector<pair<int,pair<int,int>>> &v) {
    int mstEdge = 0, connected = 0;

    // n-1 edges
    for (const auto &edge: v) {
        int val = edge.first;
        int n1 = edge.second.first, n2 = edge.second.second;

        if (!IsParentSame(n1, n2)) {
            Union(n1,n2);
            mstEdge += val;
            connected++;
        }

        if(connected == N-1) {
            break;
        }
    }

    if(connected < N-1) return -1;
    else return mstEdge;
}

int main() {
    int edgeSum = 0;
    vector<pair<int,pair<int,int>>> v;

    cin >> N;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        for(int j = 1; j <= N; j++) {
            char c; cin >> c;
            int edgeVal;

            if(c == '0') {
                edgeVal = 0;
            }
            else if(c >= 'a' && c <= 'z') {
                edgeVal = int(c-'a')+1;
            }
            else {
                edgeVal = int(c) - 38;
            }

            edgeSum += edgeVal;
            if(edgeVal != 0) {
                v.push_back({edgeVal, {i, j}});
            }
        }
    }

    sort(v.begin(), v.end());

    int mstEdge = MakeMST(v);
    if(mstEdge == -1) {
        cout << -1;
    }
    else {
        int answer = edgeSum - mstEdge;
        cout << answer;
    }
}