#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string answer;
string str1, str2;
int d[1010][1010];

void Print() {
    for(int i = 1; i <= str1.size(); i++) {
        for(int j = 1; j <= str2.size(); j++) {
            cout << d[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

void dfs(int i, int j) {
    if(i <= 0 || j <= 0) {
        return;
    }

    if (d[i][j] == d[i - 1][j]) {
        dfs(i-1, j);
    }
    else if(d[i][j] == d[i][j-1]) {
        dfs(i, j-1);
    }
    else {
        answer.push_back(str1[i-1]);
        dfs(i-1, j-1);
    }
}

int main() {
    cin >> str1 >> str2;
    if(str1.size() > str2.size()) {
        swap(str1, str2);
    }

    // make d[][]
    for(int i = 1; i <= str1.size(); i++) {
        char c1 = str1[i-1];
        for(int j = 1; j <= str2.size(); j++) {
            char c2 = str2[j-1];

            if(c1 == c2) {
                d[i][j] = d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    // find LCS sequence
    dfs((int)str1.size(), (int)str2.size());

    reverse(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    cout << answer;
}