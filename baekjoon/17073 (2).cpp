#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
#define MAX 500000

int N, W;
int d[MAX+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W;
    for(int i = 0; i < N-1; i++) {
        int a,b; cin >> a >> b;
        d[a]++;
        d[b]++;
    }

    int leaf = 0;
    for(int i = 2; i <= N; i++) {
        if(d[i] == 1) leaf++;
    }

    double answer = (double)W / leaf;
    cout << fixed << setprecision(10) << answer;
}