#include <iostream>
using namespace std;

long long N, B;
long long arr[6][6];
long long ans[6][6];

// arr1 = arr1 * arr2
void multiple(long long arr1[6][6], long long arr2[6][6]) {
    long long tmp[6][6];
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            tmp[r][c] = 0;
            for(int k = 0; k < N; k++) {
                tmp[r][c] += (arr1[r][k] * arr2[k][c]) % 1000;
            }
        }
    }

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            arr1[r][c] = tmp[r][c] % 1000;
        }
    }
}

void Print(long long arr[6][6]) {
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cout << arr[r][c] % 1000 << ' ';
        } cout << '\n';
    }
}

int main() {


    cin >> N >> B;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
        ans[i][i] = 1; // 단위 행렬
    }

    while(B > 0) {
        if(B % 2 == 1) {
            multiple(ans, arr);
        }
        multiple(arr, arr);
        B /= 2;
    }

    Print(ans);
}