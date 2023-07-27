#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define DIA 0
#define IRON 1
#define STONE 2

int answer = 100000000;

struct Group {
    vector<string> minerals;
};

// mineral ? pick ?? ??? ?? ??? ??
int Cal(const string &mineral, int pick) {
    if(pick == DIA) {
        return 1;
    } else if (pick == IRON) {
        if(mineral == "diamond") return 5;
        else return 1;
    } else {
        if(mineral == "diamond") return 25;
        else if(mineral == "iron") return 5;
        else return 1;
    }
}

// ??? ??? minerals ??? ?? ? ???? ??
int GetStress(const vector<string> &minerals, int pick) {
    int stress = 0;
    for(const auto &mineral : minerals) {
        stress += Cal(mineral, pick);
    }
    return stress;
}

// ?? ??
vector<Group> DivideGroups(const vector<string> &minerals) {
    vector<Group> groups;
    for(int i = 0; i < minerals.size(); i+=5) {
        Group group;
        for(int j = i; j < i+5; j++) {
            if(j >= minerals.size()) break;
            group.minerals.push_back(minerals[j]);
        }
        groups.push_back(group);
    }
    return groups;
}

// ??? ??
vector<int> GetPicks(const vector<int> &picks, int groupCnt) {
    vector<int> v;
    for(int i = 0; i < picks[DIA]; i++) {
        v.push_back(DIA);
        if(v.size() == groupCnt) return v;
    }
    for(int i = 0; i < picks[IRON]; i++) {
        v.push_back(IRON);
        if(v.size() == groupCnt) return v;
    }
    for(int i = 0; i < picks[STONE]; i++) {
        v.push_back(STONE);
        if(v.size() == groupCnt) return v;
    }
    return v;
}

bool visited[55];

int CalStress(const vector<Group> &groups, const vector<int> &picksList, const vector<int> &v) {
    int stress = 0;
    for(int i = 0; i < v.size(); i++) {
        int pick = v[i];
        if(i >= groups.size()) break;
        stress += GetStress(groups[i].minerals, pick);
    }
    return stress;
}

void dfs(const vector<Group> &groups, const vector<int> &picksList, vector<int> &v, int depth) {
    if(depth == picksList.size()) {
        int stress = CalStress(groups, picksList, v);
        answer = min(answer, stress);
        return;
    }

    for(int i = 0; i < picksList.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(picksList[i]);
        dfs(groups, picksList, v, depth + 1);
        visited[i] = false;
        v.pop_back();
    }
}

int solution(vector<int> picks, vector<string> minerals) {

    // ?? ??
    vector<Group> groups = DivideGroups(minerals);
    // ??? ??
    vector<int> picksList = GetPicks(picks, (int)groups.size());

    vector<int> v;
    dfs(groups, picksList, v, 0);

    return answer;
}

int main() {
//    vector<int> picks = {1, 3, 2};
//    vector<string> minerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};

//    vector<string> minerals = {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"};
//    vector<int> picks = {0,1,1};

    vector<string> minerals = {"iron", "iron", "iron", "iron", "diamond", "diamond", "diamond"};
    vector<int> picks = {1,0,1};

    int res = solution(picks, minerals);
    cout << endl;
    cout << "ans : " << res << endl;
}