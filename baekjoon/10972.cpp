#include <iostream>
using namespace std;
#include <algorithm>

int main() {
    int n;
    cin >> n;
    int arr[10001];

    for(int i = 0; i < n; i++) cin >> arr[i];

    if(next_permutation(arr, arr+n)) {
        for(int i = 0; i < n; i++) cout << arr[i] << ' ';
    }
    else cout << -1;
}