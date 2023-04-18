#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1010];
int answer;

void CalTwoSum(vector<int> &sums) {
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            sums.push_back(arr[i] + arr[j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> sums;
    CalTwoSum(sums);
    sort(sums.begin(), sums.end());

    for(int i = 0; i < N; i++) {
        int goal = arr[i];

        for(int j = 0; j < N; j++) {
            int target = goal - arr[j];
            // found target
            if(binary_search(sums.begin(), sums.end(), target)) {
                answer = max(answer, goal);
            }
        }
    }

    cout << answer;
}