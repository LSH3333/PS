#include <iostream>
#include <string>
using namespace std;

int CountZero(const string &str) {
    int cnt = 0;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] == '0') cnt++;
        else break;
    }
    return cnt;
}

int CountOne(const string &str) {
    int cnt = 0;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] == '1') cnt++;
        else break;
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        bool can = true;
        string str; cin >> str;

        while(!str.empty()) {
            cout << str << endl;
            if (str.front() == '0') {
                if(str[1] == '0') { can = false; break; }
                else { str = str.substr(2); }
            }
            else { // 1
                // 1 이후 최소 2개의 0 필요
                int cnt = CountZero(str);
                if(cnt < 2) { can = false; break; }
                // 1..
                str = str.substr(cnt+1);
                for(int i = 0; i < str.size(); i++) {
                    if(str[i] == '1') cnt++;
                    else break;
                }
                // 마지막 1 남기고 이전 1 지굼
                str = str.substr(cnt-1);
                cout << "2: " << str << endl;

                // 1..
                if(str.size() == 1) {
                    break;
                }
                if(str[1] == '0') {
                    str = str.substr(1);
                }
                else {
                    cnt = CountOne(str);
                    string tmp = str.substr(cnt); // 0..
                    int zeroCnt = 0;
                    for(int i = 0; i < tmp.size(); i++) {
                        if(tmp[i] == '0') zeroCnt++;
                        else break;
                    }

                    if(zeroCnt == 1) str = tmp;
                    else str = str.substr(cnt-1);
                }
            }
        }

        can ? cout << "YES\n" : cout << "NO\n";
    }

}