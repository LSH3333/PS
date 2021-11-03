#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[22][22];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> teamIdx;
    teamIdx.push_back(-1);
    for(int i = 0; i < n/2; i++)
        teamIdx.push_back(1);
    for(int j = 0; j < n/2; j++)
        teamIdx.push_back(0);

    int ans = 0;
    bool ansTrigger = false;

    do {
        /*for(int i = 1; i <= n; i++)
            cout << teamIdx[i] << ' ';
        cout << endl;*/
        vector<int> startTeam; startTeam.push_back(-1);
        vector<int> linkTeam; linkTeam.push_back(-1);
        int startTeamScore = 0;
        int linkTeamScore = 0;

        for(int i = 1; i <= n; i++) { // 각각 팀에 인원 배정
            if(teamIdx[i] == 1) {
                startTeam.push_back(i);
            }
            else {
                linkTeam.push_back(i);
            }
        }

        /*for(int x : startTeam) cout << x << ' ';
        cout << endl;*/

        for(int i = 1; i <= n/2; i++) {
            for(int j = i+1; j <= n/2; j++) {
                startTeamScore += arr[startTeam[i]][startTeam[j]];
                startTeamScore += arr[startTeam[j]][startTeam[i]];

                linkTeamScore += arr[linkTeam[i]][linkTeam[j]];
                linkTeamScore += arr[linkTeam[j]][linkTeam[i]];
            }
        }
        int sub = startTeamScore - linkTeamScore;
        if(sub < 0) sub *= -1;
        if(!ansTrigger) {
            ansTrigger = true;
            ans = sub;
        }
        ans = min(ans, sub);
    } while(prev_permutation(teamIdx.begin()+1, teamIdx.end()));

    cout << ans;
}