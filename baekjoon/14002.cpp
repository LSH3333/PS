#include <iostream>
#include <vector>
using namespace std;

int N, lis, lisIdx;
int arr[1010];
int d[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        int maxVal = 1;
        for(int j = i-1; j >= 0; j--) {
            if(arr[j] < arr[i]) {
                maxVal = max(maxVal, d[j]+1);
            }
        }
        d[i] = maxVal;
        if(d[i] > lis) {
            lis = d[i];
            lisIdx = i;
        }
    }

    vector<int> answer(lis+1);
    for(int i = lisIdx; i >= 0; i--) {
        if(d[i] == lis) {
            answer[lis] = arr[i];
            lis--;
        }
    }

    cout << answer.size()-1 << '\n';
    for(int i = 1; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}