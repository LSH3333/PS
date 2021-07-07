#include <iostream>
using namespace std;
#include <algorithm>

int main() {
    int arr[10001];
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(prev_permutation(arr, arr+n)) { // true반환 하면 arr 출력
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
    else { // false 반환하면 사전순 처음임
        cout << "-1";
    }


}