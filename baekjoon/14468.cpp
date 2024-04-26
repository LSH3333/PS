#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> pos[30];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string line; cin >> line;

    for(int i = 0; i < line.size(); i++) {
        int idx = line[i] - 'A';
        pos[idx].push_back(i);
    }

    int answer = 0;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            int A1 = pos[i][0], A2 = pos[i][1];
            int B1 = pos[j][0] , B2 = pos[j][1];
            if(A1 < B1 && B1 < A2 && A2 < B2) {
                answer++;
            }
        }
    }

    cout << answer;
}