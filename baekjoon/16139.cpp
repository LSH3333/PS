#include <iostream>
using namespace std;

string str;
int mark[200010][30];
int N;

void Cal() {
    mark[0][str[0]-'a']++;

    for(int i = int('a'-'a'); i <= int('z'-'a'); i++) {
        char c = char(i+'a');

        for(int j = 1; j < str.size(); j++) {
            if(str[j] == c) {
                mark[j][c-'a'] = mark[j-1][c-'a'] + 1;
            }
            else {
                mark[j][c-'a'] = mark[j-1][c-'a'];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str;

    Cal();

    cin >> N;

    for(int i = 0; i < N; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if(l-1 < 0) {
            cout << mark[r][c-'a'] << '\n';
        }
        else {
            cout << mark[r][c-'a'] - mark[l-1][c-'a'] << '\n';
        }
    }


}