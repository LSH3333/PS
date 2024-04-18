#include <iostream>
#include <vector>
using namespace std;

int N, answer;
int goal_color[200010];
int color[200010];
vector<int> edges[200010];

void searchTree(int node, int painted, int prevNode) {

    // ??? ?? ?? ?? ??
    if(color[node] == goal_color[node]) {
        for (auto next: edges[node]) {
            if(next == prevNode) continue;
            searchTree(next, 0, node);
        }
    }
        // ?? ? ??
    else {
        // ???? ?? ?? ?? ?? ?? ?? ?? (? ?? ????)
        if (painted == goal_color[node]) {
            color[node] = goal_color[node];

            for (auto next: edges[node]) {
                if(next == prevNode) continue;
                searchTree(next, goal_color[node], node);
            }
        }
            // ???? ?? ?? ?? ?? ?? ? ?? (? ??? ????)
        else {
            answer++;
            color[node] = goal_color[node];

            for (auto next: edges[node]) {
                if(next == prevNode) continue;
                searchTree(next, goal_color[node], node);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> goal_color[i];
    }

    for(int i = 0; i < N-1; i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    searchTree(1, 0, -1);

    cout << answer;
}