#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 201
#define INF 1000000000
int d[MAX][MAX];
int goalAlp, goalCop;


void Init() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            d[i][j] = INF;
        }
    }
}

void FindGoal(const vector<vector<int>> &problems) {
    for (const auto &problem: problems) {
        goalAlp = max(goalAlp, problem[0]);
        goalCop = max(goalCop, problem[1]);
    }
}


int solution(int alp, int cop, vector<vector<int>> problems) {
    Init();
    FindGoal(problems);
    int answer = INF;

    alp = min(alp, goalAlp);
    cop = min(cop, goalCop);

    d[alp][cop] = 0;

    for(int i = alp; i <= goalAlp; i++) {
        for(int j = cop; j <= goalCop; j++) {
            int i_idx = min(i + 1, goalAlp), j_idx = min(j + 1, goalCop);
            // ??? +1
            d[i_idx][j] = min(d[i_idx][j], d[i][j] + 1);
            // ??? +1
            d[i][j_idx] = min(d[i][j_idx], d[i][j] + 1);

            // ???
            for (const auto &prob: problems) {
                int alp_req = prob[0], cop_req = prob[1], alp_rwd = prob[2], cop_rwd = prob[3], cost = prob[4];
                // ?? ?? ??
                if(alp_req > i || cop_req > j) continue;

                i_idx = min(i + alp_rwd, goalAlp);
                j_idx = min(j + cop_rwd, goalCop);
                d[i_idx][j_idx] = min(d[i_idx][j_idx], d[i][j] + cost);
            }
        }
    }


    answer = d[goalAlp][goalCop];
    return answer;
}

int main() {
//    int alp = 0;
//    int cop = 0;
//    vector<vector<int>> problems = {
//            {0, 0, 2, 1, 2},
//            {4, 5, 3, 1, 2},
//            {4, 11, 4, 0, 2},
//            {10, 4, 0, 4, 2}
//    };

    vector<vector<int>> problems = {
            {10, 15, 2, 1, 2},
            {20, 20, 3, 3, 4}
    };

    int ans = solution(10,10, problems);
    cout << endl << ans;
}