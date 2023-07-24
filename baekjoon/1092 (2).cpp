#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> cranes, boxes;

int FindCraneForBox(int boxWeight, int craneBegin) {
    for(int crane = craneBegin; crane < cranes.size(); crane++) {
        if(cranes[crane] >= boxWeight) {
            return crane;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        cranes.push_back(n);
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        boxes.push_back(n);
    }

    sort(cranes.begin(), cranes.end(), greater<>());
    sort(boxes.begin(), boxes.end(), greater<>());

    int movedBox = 0, answer = 0;
    while(movedBox < M) {
        bool moved = false;
        int craneIdx = 0;
        for(int box = 0; box < boxes.size(); box++) {
            if(boxes[box] == -1) continue;
            int res = FindCraneForBox(boxes[box], craneIdx);
            if(res != -1) {
                boxes[box] = -1; // ?? ?? ??
                movedBox++;
                moved = true;
                craneIdx = res + 1;
            }
        }

        if(!moved) {
            answer = -1;
            break;
        }
        answer++;
    }

    cout << answer;

}