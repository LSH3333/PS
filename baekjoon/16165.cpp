#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unordered_map<string, vector<string>> teamMembers;
    unordered_map<string, string> memberTeam;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string team;
        int cnt;
        cin >> team >> cnt;

        vector<string> members;
        for(int j = 0; j < cnt; j++) {
            string member; cin >> member;
            members.push_back(member);
            memberTeam[member] = team;
        }

        sort(members.begin(), members.end());
        teamMembers[team] = members;
    }

    for(int i = 0; i < M; i++) {
        string str;
        int n;
        cin >> str >> n;

        // ?? ??? ???, ????? ??? ??
        if(n == 0) {
            for (const auto &member: teamMembers[str]) {
                cout << member << '\n';
            }
        }
            // ?? ???, ? ?? ??
        else {
            cout << memberTeam[str] << '\n';
        }
    }

}
