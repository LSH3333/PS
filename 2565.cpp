#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++) {
        int num1;
        cin >> num1;
        v[i].push_back(num1);
        int num2;
        cin >> num2;
        v[i].push_back(num2);
    }

    sort(v.begin(), v.end()); // 좌측 전봇대 기준 렬

    int lis[101] = {0}; // 오른쪽 전봇대의 LIS 저장
    lis[0] = 1; // LIS의 첫 요소는 항상 1
    for(int i = 1; i < n; i++) {
        int max = 0;
        for(int j = 0; j < i; j++) {
            if(v[j][1] < v[i][1]) {
                if(lis[j] > max) max = lis[j];
            }
        }
        lis[i] = max + 1;
    }


    cout << n - *max_element(lis, lis+n);

}