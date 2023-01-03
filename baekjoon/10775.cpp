#include <iostream>
using namespace std;

int G, P;
int parent[100010];
int answer;

int GetParent(int n) {
    if(n == parent[n]) return n;
    return parent[n] = GetParent(parent[n]);
}

bool GetLoc(int n) {
    int p = GetParent(n);
    if(p == 0) {
        return false;
    }
    else {
        parent[n] = p-1;
        parent[p] = p-1;
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> G >> P;
    for(int i = 0; i <= G; i++) parent[i] = i;
    for(int i = 1; i <= P; i++) {
        int n; cin >> n;
        bool res = GetLoc(n);
        if(!res) {
            answer = i;
            break;
        }
    }

    if(answer == 0) cout << P;
    else cout << answer-1;
}