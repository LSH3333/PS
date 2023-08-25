#include <iostream>
#include <vector>
using namespace std;

#define INF 10000000

int N;
int a[1001][3];
//int d1[1001][3], d2[1001][3], d3[1001][3];

void MakeD(vector<vector<int>> &d) {
    for(int i = 2; i < N; i++) {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + a[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + a[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + a[i][2];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    // 1 ?? ???
    vector<vector<int>> d1(1001, vector<int>(3, 0));
    d1[1][0] = a[1][0];
    d1[1][1] = INF;
    d1[1][2] = INF;
    MakeD(d1);
    d1[N][0] = INF;
    d1[N][1] = min(d1[N-1][0], d1[N-1][2]) + a[N][1];
    d1[N][2] = min(d1[N-1][0], d1[N-1][1]) + a[N][2];

    // 1 ?? ???
    vector<vector<int>> d2(1001, vector<int>(3, 0));
    d2[1][0] = INF;
    d2[1][1] = a[1][1];
    d2[1][2] = INF;
    MakeD(d2);
    d2[N][0] = min(d2[N-1][1], d2[N-1][2]) + a[N][0];
    d2[N][1] = INF;
    d2[N][2] = min(d2[N-1][0], d2[N-1][1]) + a[N][2];

    // 1 ?? ???
    vector<vector<int>> d3(1001, vector<int>(3, 0));
    d3[1][0] = INF;
    d3[1][1] = INF;
    d3[1][2] = a[1][2];
    MakeD(d3);
    d3[N][0] = min(d3[N-1][1], d3[N-1][2]) + a[N][0];
    d3[N][1] = min(d3[N-1][0], d3[N-1][2]) + a[N][1];
    d3[N][2] = INF;

    int answer = INF;
    answer = min(d1[N][0], min(d1[N][1], d1[N][2]));
    answer = min(answer, min(d2[N][0], min(d2[N][1], d2[N][2])));
    answer = min(answer, min(d3[N][0], min(d3[N][1], d3[N][2])));
    cout << answer;

}