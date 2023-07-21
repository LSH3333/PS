#include <iostream>
using namespace std;

int N, maxAns, minAns;
int a[100010][3];
int maxD[2][3];
int minD[2][3];


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for(int j = 0; j < 3; j++) {
        maxD[0][j] = a[0][j];
        minD[0][j] = a[0][j];
    }

    for(int i = 1; i < N; i++) {
        if(i % 2 == 0) {
            maxD[0][0] = a[i][0] + max(maxD[1][0], maxD[1][1]);
            maxD[0][1] = a[i][1] + max(maxD[1][0], max(maxD[1][1], maxD[1][2]));
            maxD[0][2] = a[i][2] + max(maxD[1][1], maxD[1][2]);

            minD[0][0] = a[i][0] + min(minD[1][0], minD[1][1]);
            minD[0][1] = a[i][1] + min(minD[1][0], min(minD[1][1], minD[1][2]));
            minD[0][2] = a[i][2] + min(minD[1][1], minD[1][2]);
        }
        else {
            maxD[1][0] = a[i][0] + max(maxD[0][0], maxD[0][1]);
            maxD[1][1] = a[i][1] + max(maxD[0][0], max(maxD[0][1], maxD[0][2]));
            maxD[1][2] = a[i][2] + max(maxD[0][1], maxD[0][2]);

            minD[1][0] = a[i][0] + min(minD[0][0], minD[0][1]);
            minD[1][1] = a[i][1] + min(minD[0][0], min(minD[0][1], minD[0][2]));
            minD[1][2] = a[i][2] + min(minD[0][1], minD[0][2]);
        }
    }


    if(N % 2 == 0) {
        maxAns = max(maxD[1][0], max(maxD[1][1], maxD[1][2]));
        minAns = min(minD[1][0], min(minD[1][1], minD[1][2]));
    }
    else {
        maxAns = max(maxD[0][0], max(maxD[0][1], maxD[0][2]));
        minAns = min(minD[0][0], min(minD[0][1], minD[0][2]));
    }

    cout << maxAns << ' ' << minAns;
}