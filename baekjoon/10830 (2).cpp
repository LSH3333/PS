#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000
long long N, B;



vector<vector<long long>> multiple(const vector<vector<long long>> &arr1, const vector<vector<long long>> &arr2) {
    vector<vector<long long>> ret(N, vector<long long>(N, 0));
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {

            for(int i = 0; i < N; i++) {
                ret[r][c] = (ret[r][c] + ((arr1[r][i] * arr2[i][c]) % MOD)) % MOD;
            }

        }
    }

    return ret;
}


vector<vector<long long>> Cal(vector<vector<long long>> arr, long long b) {
    if(b == 1) {
        return arr;
    }

    vector<vector<long long>> res = Cal(arr, b/2);
    if(b % 2 == 0) {
        return multiple(res, res);
    }
    else {
        return multiple(multiple(res, res), arr);
    }
}

int main() {
    cin >> N >> B;
    vector<vector<long long>> arr(N, vector<long long>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<long long>> res = Cal(arr, B);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << res[i][j] % MOD<< ' ';
        }cout<<endl;
    }


}