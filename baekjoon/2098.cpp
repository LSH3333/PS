#include <iostream>
#include <cstring>
using namespace std;

#define INF 100000000
int N;
int edges[17][17];
int d[17][1<<16]; // 1<<16 = 10000000000000000(2)

int dfs(int cur, int curBit) {
    // N=4?? (1<<N)-1 = 1111(2), ? ?? ?? ?? ??
    if(curBit == (1<<N)-1) {
        if(edges[cur][0] == 0) return INF;
        else return edges[cur][0];
    }

    // ?? ?? ??
    if(d[cur][curBit] != -1) {
        return d[cur][curBit];
    }
    // ?? ??
    d[cur][curBit] = INF;

    for(int i = 0; i < N; i++) {
        // ? ??
        if(edges[cur][i] == 0) continue;
        // (0011 & 0010) == (0010) ?? ?? 1 ?? ?? ??? ??
        if((curBit & (1<<i)) == (1<<i)) continue;

        d[cur][curBit] = min(d[cur][curBit],
                             dfs(i, curBit | (1<<i)) + edges[cur][i]); // 0001 | 0010 = 0011
    }

    return d[cur][curBit];
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> edges[i][j];
        }
    }

    memset(d, -1, sizeof(d));

    cout << dfs(0, 1); // ?? 0? ?? ?? ??


}