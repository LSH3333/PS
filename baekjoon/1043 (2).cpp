#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer;
vector<int> knows;
vector<vector<int>> parties;
int parent[51];

int GetParent(int node) {
    if(parent[node] == node) return node;
    return parent[node] = GetParent(parent[node]);
}

void Union(int n1, int n2) {
    n1 = GetParent(n1);
    n2 = GetParent(n2);
    parent[max(n1, n2)] = min(n1, n2);
}

void pollutes(int n) {
    knows[n] = true;
    if(n == parent[n]) return;
    pollutes(parent[n]);
}

bool CheckParent(int n) {
    for(auto x : knows) {
        if(GetParent(x) == GetParent(n)) return false;
    }
    return true;
}

bool CanTell(const vector<int> &party) {
    for(auto x : party) {
        if(!CheckParent(x)) return false;
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    int knowsCnt; cin >> knowsCnt;
    for(int i = 0; i < knowsCnt; i++) {
        int n; cin >> n;
        knows.push_back(n);
    }

    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        vector<int> party;
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            party.push_back(x);
        }
        parties.push_back(party);
    }

    // Union
    for(auto &party : parties) {
        int target = party.front();

        for(int i = 1; i < party.size(); i++) {
            Union(target, party[i]);
        }
    }

    for(const auto &party : parties) {
        if(CanTell(party)) answer++;
    }
    cout << answer;
}