#include <iostream>
#include <vector>
using namespace std;

int N, L;

bool IsUpperPossible(vector<int> &road, vector<bool> &bridge, int idx) {
    bool possible = true;
    int h = road[idx];
    for(int i = idx-L+1; i <= idx; i++) {
        if(i <= 0 || road[i] != h || bridge[i]) {
            possible = false;
            break;
        }
    }

    if(possible) {
        for(int i = idx-L+1; i <= idx; i++) {
            bridge[i] = true;
            road[i] = h;
        }
    }
    return possible;
}

bool IsDownPossible(vector<int> &road, vector<bool> &bridge, int idx) {
    bool possible = true;
    int h = road[idx+1];
    for(int i = idx+1; i <= idx+L; i++) {
        if(i >= road.size() || road[i] != h || bridge[i]) {
            possible = false;
            break;
        }
    }

    if(possible) {
        for(int i = idx+1; i <= idx+L; i++) {
            bridge[i] = true;
            road[i] = h;
        }
    }
    return possible;
}

bool Try(vector<int> &road, vector<bool> &bridge, int idx) {
    if(idx == road.size()-1) {
        return true;
    }

    if(road[idx+1] == road[idx]) {
        return Try(road, bridge, idx+1);
    }
    // Upper
    if(road[idx]+1 == road[idx+1]) {
        if(IsUpperPossible(road, bridge, idx)) {
            return Try(road, bridge, idx+1);
        }
    }
    // Down
    if(road[idx] == road[idx+1]+1) {
        if(IsDownPossible(road, bridge, idx)) {
            return Try(road, bridge, idx+L);
        }
    }

    return false;
}

int main() {
    int answer = 0;
    vector<vector<int>> roads;

    cin >> N >> L;
    for(int r = 0; r < N; r++) {
        vector<int> road = {0};
        for(int c = 0; c < N; c++) {
            int n; cin >> n;
            road.push_back(n);
        }
        roads.push_back(road);
    }

    for(int c = 1; c <= N; c++) {
        vector<int> road = {0};
        for(int r = 0; r < N; r++) {
            road.push_back(roads[r][c]);
        }
        roads.push_back(road);
    }

    //
    for(auto &road : roads) {
        vector<bool> bridge(road.size(), false);

        if (Try(road, bridge, 1)) {
            answer++;
        }
    }

    cout << answer;
}