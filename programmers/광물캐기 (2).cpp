#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> MakeGroup(const vector<int> &picks) {
    vector<int> v;
    for(int i = 0; i < picks[0]; i++) {
        v.push_back(0);
    }
    for(int i = 0; i < picks[1]; i++) {
        v.push_back(1);
    }
    for(int i = 0; i < picks[2]; i++) {
        v.push_back(2);
    }
    return v;
}

int GetCost(int pick, const string &mineral ) {
    if (mineral == "diamond") {
        if(pick == 0) return 1;
        else if(pick == 1) return 5;
        else return 25;
    }
    else if(mineral == "iron") {
        if(pick == 2) return 5;
        else return 1;
    }
    else {
        return 1;
    }
}

int Mining(const vector<int> &v, const vector<string> &minerals) {
    int idx = 0, totalCost = 0;
    for(auto pick : v) {
        for(int i = 0; i < 5 && idx < minerals.size(); i++) {
            totalCost += GetCost(pick, minerals[idx++]);
        }
    }
    return totalCost;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 100000000;
    vector<int> v = MakeGroup(picks);

    do {
        int totalCost = Mining(v, minerals);
        answer = min(answer, totalCost);
    } while (next_permutation(v.begin(), v.end()));

    cout << answer;
    return answer;
}

int main() {
    vector<int> picks = {1,3,2};
    vector<string> minerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};
    solution(picks, minerals);
}