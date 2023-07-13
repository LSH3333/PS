#include <iostream>
using namespace std;

int N;
int mark[101][101];


int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mark[i][j];
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(mark[i][k] + mark[k][j] >= 2) {
                    mark[i][j] = 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << mark[i][j] << ' ';
        } cout << '\n';
    }
}