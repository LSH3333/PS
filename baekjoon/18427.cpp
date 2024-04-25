#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;

#define MOD 10007
int N, M, H;
vector<int> b[55];
int d[55][1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> H;
    cin.ignore();

    for(int i = 1; i <= N; i++) {
        string str;
        getline(cin, str);
        stringstream ss(str);

        int n;
        while(ss >> n) {
            b[i].push_back(n);
        }
    }


    for(int i = 0; i <= N; i++) {
        d[i][0] = 1;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= H; j++) {
            d[i][j] = (d[i][j] + d[i-1][j]) % MOD;
            for (int k = 0; k < b[i].size(); k++) {
                int block = b[i][k];
                if(j - block >= 0) {
                    d[i][j] = (d[i][j] + d[i-1][j-block]) % MOD;
                }
            }
        }
    }


    cout << d[N][H] % MOD;
}