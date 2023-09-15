#include <iostream>
using namespace std;

int N, X;
int arr[250001];
int d[250001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int maxVisitor = 0, cnt = 0;
    cin >> N >> X;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for(int i = 0; i < X; i++) {
        sum += arr[i];
    }
    d[X-1] = sum;
    maxVisitor = max(maxVisitor, sum);

    for(int i = 1; i <= N-X; i++) {
        sum -= arr[i-1];
        sum += arr[i-1+X];
        d[i-1+X] = sum;
        maxVisitor = max(maxVisitor, sum);
    }

    for(int i = 0; i < N; i++) {
        if(d[i] == maxVisitor) {
            cnt++;
        }
    }

    if(maxVisitor == 0) {
        cout << "SAD";
    }
    else {
        cout << maxVisitor << '\n' << cnt;
    }
}