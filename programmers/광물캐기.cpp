#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define DIA 0
#define IRON 1
#define STONE 2

struct Group {
    int score;
    vector<string> minerals;
    int groupNum; // ?? ?????? ??? ????
};

bool cmp(const Group &g1, const Group &g2) {
    return g1.score > g2.score;
}

int getScore(const string &mineral) {
    if(mineral == "diamond") return 25;
    else if(mineral == "iron") return 5;
    else return 1;
}

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

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int pickCnt = picks[0] + picks[1] + picks[2];

    // ?? 5?? ?? ??
    vector<Group> groups;
    for(int i = 0; i < minerals.size(); i+=5) {
        if(i >= minerals.size()) break;
        int scoreTotal = 0;
        vector<string> tmp;

        for(int j = i; j < i+5; j++) {
            if(j >= minerals.size()) break;
            scoreTotal += getScore(minerals[j]);
            tmp.push_back(minerals[j]);
        }

        groups.push_back({scoreTotal, tmp, i/5});
    }

    // ?? ?? ???? ??
    sort(groups.begin(), groups.end(), cmp);

    for (auto group: groups) {
        if(group.groupNum >= pickCnt) continue;

        if(picks[0] > 0) {
            answer += GetStress(group.minerals, DIA);
            picks[0]--;
        }
        else if(picks[1] > 0) {
            answer += GetStress(group.minerals, IRON);
            picks[1]--;
        }
        else if(picks[2] > 0) {
            answer += GetStress(group.minerals, STONE);
            picks[2]--;
        }
            // ??? ??
        else {
            break;
        }

    }


    return answer;
}

int main() {
//    vector<int> picks = {1, 3, 2};
//    vector<string> minerals = {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"};

//    vector<string> minerals = {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"};
//    vector<int> picks = {0,1,1};

    vector<string> minerals = {"iron", "iron", "iron", "iron", "diamond", "diamond", "diamond"};
    vector<int> picks = {1,0,1};

    cout << solution(picks, minerals);
}