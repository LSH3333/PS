#include <iostream>
using namespace std;
#include <algorithm> // next_permutation
#include <vector>

int main() {
    int n;
    int arr[12];
    int cal[4]; // +, -, *, /
    // 각 연산자를 몇개 쓸수 있는지
    // cal[4] = {2,1,1,1} 이라면 v = {0, 0, 1, 2, 3}
    vector<int> v;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++) cin >> cal[i];

    // 연산자 벡터 생성
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < cal[i]; j++) {
            v.push_back(i);
        }
    }

    int nmax = -100000001; // 최댓값
    int nmin = 100000001; // 최솟값
    do {
        int res = arr[0];
        for(int i = 1; i < n; i++) {


            switch(v[i-1]) {
                case 0: // +
                    res += arr[i];
                    break;

                case 1: // -
                    res -= arr[i];
                    break;

                case 2: // *
                    res *= arr[i];
                    break;

                case 3: // /
                    res /= arr[i];
                    break;
            }

        }
        // 최댓값, 최솟값 갱신
        nmax = max(nmax, res);
        nmin = min(nmin, res);
    } while(next_permutation(v.begin(), v.end()));

    cout << nmax << '\n' << nmin;
}