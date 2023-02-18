#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> v;
    v.push_back(arr[0]);

    for(int i = 1; i < N; i++) {
        int n = arr[i];

        auto it = lower_bound(v.begin(), v.end(), n);

        if(it == v.end()) {
            v.push_back(n);
        }
        else {
            *it = n;
        }
    }

    cout << N - (int) v.size();
}