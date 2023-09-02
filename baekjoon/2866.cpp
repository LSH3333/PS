#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

char board[1010][1010];

vector<string> MakeStrings(int R, int C) {
    vector<string> v;

    for(int c = 0; c < C; c++) {
        string str;
        for(int r = R-1; r >= 0; r--) {
            str.push_back(board[r][c]);
        }
        v.push_back(str);
    }
    return v;
}

int main() {
    int R, C; cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    vector<string> strings = MakeStrings(R, C);
    int maxVal = 0;
    for(int i = 1; i <= strings.front().size(); i++) {
        set<string> st;
        for(const auto &str : strings) {
            st.insert(str.substr(0, i));
        }

        // ?? ??
        if (st.size() != strings.size()) {
            maxVal = max(maxVal, i);
        }
    }

    int answer = R - maxVal - 1;
    cout << answer;
}
