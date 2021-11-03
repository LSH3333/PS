#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int arr[9];
    int sum = 0;
    int target;

    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr+9);

    /* 난쟁이가 아닌 두명의 키의 합 */
    target = sum - 100;

    int ans1,ans2;
    for(int i = 0; i < 9; i++) {
        for(int j = i+1; j < 9; j++) {
            if(arr[i] + arr[j] == target) {
                ans1 = i; ans2 = j;
            }
        }
    }

    for(int i = 0; i < 9; i++) {
        if(i == ans1 || i == ans2) continue;
        cout << arr[i] << '\n';
    }

}