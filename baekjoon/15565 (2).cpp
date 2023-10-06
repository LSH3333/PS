#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000001
int N, K, answer=MAX;
int arr[1000001];

int main() {
    vector<int> lions;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(arr[i] == 1) {
            lions.push_back(i);
        }
    }

    if(lions.size() < K) {
        cout << -1;
    }
    else {
        for(int i = K-1; i < lions.size(); i++) {
            answer = min(answer, lions[i] - lions[i-K+1] + 1);
        }
        cout << answer;
    }
}