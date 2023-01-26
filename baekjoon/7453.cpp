#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 4010

int N;
int arr1[MAX], arr2[MAX], arr3[MAX], arr4[MAX];
vector<int> A, B;
long long answer;

void MakeAB() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            A.push_back(arr1[i] + arr2[j]);
            B.push_back(arr3[i] + arr4[j]);
        }
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr1[i] >> arr2[i] >> arr3[i] >> arr4[i];
    }

    MakeAB();

    for(auto a_it = A.begin(); a_it != A.end(); a_it++) {
        int findVal = -1 * (*a_it);
        int begin = lower_bound(B.begin(), B.end(), findVal)- B.begin();
        int end = upper_bound(B.begin(), B.end(), findVal)- B.begin();
        answer += end - begin;
    }

    cout << answer;

}