#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string A, B;



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;

    sort(A.begin(), A.end(), greater<>());

    do {
        if(A.front() == '0') continue;
        if (stoi(A) < stoi(B)) {
            cout << A;
            return 0;
        }
    } while (prev_permutation(A.begin(), A.end()));

    cout << -1;
}