#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000

int N;
int edge[51][51];

void Init() {
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 51; j++) {
            if(i == j) edge[i][j] = 0;
            else edge[i][j] = INF;
        }
    }
}

void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << edge[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Init();
    cin >> N;
    while(true) {
        int a,b; cin >> a >> b;
        if(a == -1 && b == -1) break;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }


    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }


    int answer = INF;
    for(int i = 1; i <= N; i++) {
        int maxVal = 0;
        for(int j = 1; j <= N; j++) {
            maxVal = max(maxVal, edge[i][j]);
        }
        answer = min(answer, maxVal);
    }

    
    vector<int> v;
    for(int i = 1; i <= N; i++) {
        int maxVal = 0;
        for(int j = 1; j <= N; j++) {
            maxVal = max(maxVal, edge[i][j]);
        }
        if(maxVal == answer) {
            v.push_back(i);
        }
    }

    cout << answer << ' ' << v.size() << '\n';
    for(auto x : v) cout << x << ' ';
}