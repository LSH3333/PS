#include <iostream>
using namespace std;

int N;
string str1, str2;

void Click(int i, string &str) {
    if(i-1 >= 0) {
        str[i - 1] = str[i - 1] == '0' ? '1' : '0';
    }
    str[i] = str[i] == '0' ? '1' : '0';
    if(i+1 < str.size()) {
        str[i + 1] = str[i + 1] == '0' ? '1' : '0';
    }
}

int Check(string &str) {
    int clicked = 0;
    for(int i = 1; i < str.size(); i++) {
        if (str[i - 1] != str2[i - 1]) {
            Click(i, str);
            clicked++;
        }
    }

    if(str == str2) {
        return clicked;
    }
    else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> str1 >> str2;

    string str = str1;
    int res = Check(str);
    if(res != -1) {
        cout << res;
        exit(0);
    }

    str = str1;
    Click(0, str);
    res = Check(str);
    if(res != -1) {
        cout << res+1;
        exit(0);
    }

    cout << -1;
}