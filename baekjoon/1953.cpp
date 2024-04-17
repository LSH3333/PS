#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> edges[110];
int teams[110];

void dfs(int node, int team) {
    teams[node] = team;
    for (auto next : edges[node]) {
        if(teams[next] != 0) continue;
        int nextTeam = team == 1 ? 2 : 1;
        dfs(next, nextTeam);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            int n; cin >> n;
            edges[i].push_back(n);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(teams[i] != 0) continue;
        dfs(i, 1);
    }

    vector<int> team1, team2;
    for(int i = 1; i <= N; i++) {
        if(teams[i] == 1) {
            team1.push_back(i);
        } else {
            team2.push_back(i);
        }
    }

    cout << team1.size() << '\n';
    for(auto x : team1) {
        cout << x << ' ';
    } cout << '\n';

    cout << team2.size() << '\n';
    for(auto x : team2) {
        cout << x << ' ';
    }
}