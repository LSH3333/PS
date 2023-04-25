#include <string>
#include <vector>
#include <iostream>
using namespace std;

int Cal(vector<int> &v, int cap, int idx) {
    if(idx < 0) return -1;
    for(int i = idx; i >= 0; i--) {
        if(v[i] == 0) continue;
        if(cap <= 0) return i;
        int cnt = min(cap, v[i]);
        v[i] -= cnt;
        cap -= cnt;

        if(v[i] > 0) return i;
    }
    return -1;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    int del_idx = -1, pickup_idx = -1;

    for(int i = n-1; i >= 0; i--) {
        if(deliveries[i] != 0) { del_idx = i; break;}
    }
    for(int i = n-1; i >= 0; i--) {
        if(pickups[i] != 0) { pickup_idx = i; break;}
    }
    // ??, ?? ?? ?? ?? ?? ?? ??
    if(del_idx == -1 && pickup_idx == -1) {
        return 0;
    }

    while(del_idx >= 0 || pickup_idx >= 0) {
        answer += max(del_idx+1, pickup_idx+1) * 2;
        del_idx = Cal(deliveries, cap, del_idx);
        pickup_idx = Cal(pickups, cap, pickup_idx);
    }

    return answer;
}

int main() {
//    int cap = 4;
//    int n = 5;
//    vector<int> deliveries = {1,0,3,1,2};
//    vector<int> pickups = {0,3,0,4,0};
//    cout << solution(cap, n, deliveries, pickups);
    int cap = 2;
    int n = 7;
    vector<int> deliveries = {1, 0, 2, 0, 1, 0, 2};
    vector<int> pickups = {0, 2, 0, 1, 0, 2, 0};
    cout << solution(cap, n, deliveries, pickups);
}