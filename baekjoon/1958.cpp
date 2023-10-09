#include <iostream>
using namespace std;

string s1, s2, s3;
int d[110][110][110];
int answer;

int main() {
    cin >> s1 >> s2 >> s3;
    s1 = '-' + s1;
    s2 = '-' + s2;
    s3 = '-' + s3;

    for(int i = 1; i <= s1.size(); i++) {
        for(int j = 1; j <= s2.size(); j++) {
            for(int k = 1; k <= s3.size(); k++) {
                if (s1[i] == s2[j] && s2[j] == s3[k]) {
                    d[i][j][k] = max(d[i][j][k], d[i - 1][j - 1][k - 1] + 1);
                } else {
                    d[i][j][k] = max(d[i - 1][j][k], d[i][j - 1][k]);
                    d[i][j][k] = max(d[i][j][k], d[i][j][k - 1]);
                }
            }
        }
    }

    cout << d[s1.size()-1][s2.size()-1][s3.size()-1];
}