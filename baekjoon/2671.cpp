#include <iostream>
#include <string>
using namespace std;

// (100~1~ | 01)~

// return -1 : false

// part == 0 : 처음 1
// part == 1 : 00
// part == 2 : ~
// part == 3 : 1
// part == 4 : ~
int pattern1(int idx, int part, const string &str) {
    if(idx == str.size()) {
        if(part == 4) return idx;
        else return -1;
    }

    if(part == 0) {
        if(str[idx] == '0') return -1;
        else return pattern1(idx + 1, 1, str);
    }
    else if(part == 1) {
        if(str[idx] == '0' && idx+1 < str.size() && str[idx+1] == '0') {
            return pattern1(idx+2, 2, str);
        }
        else return -1;
    }
    else if(part == 2) {
        if (str[idx] == '0') {
            return pattern1(idx+1, 2, str);
        }
        else {
            return pattern1(idx+1, 4, str);
        }
    }
    else if(part == 4) {
        if(str[idx] == '0') {
            return idx;
        }
        else {
            if(idx+2 < str.size() && str[idx+1] == '0' && str[idx+2] == '1') {
                return idx+1;
            }
            else if(idx+2 < str.size() && str[idx+1] == '0' && str[idx+1] == '0') {
                return idx;
            }
            else {
                return pattern1(idx + 1, 4, str);
            }
        }
    }
}

int pattern2(int idx, const string &str) {
    if(idx+1 >= (int)str.size() || str[idx+1] != '1') {
        return -1;
    }
    else
        return idx + 2;
}

int main() {
    string str; cin >> str;

    bool isSubmarine = true;
    int idx = 0;
    while(idx < str.size()) {
        if (str[idx] == '0') {
            idx = pattern2(idx, str);
        }
        else {
            idx = pattern1(idx, 0, str);
        }
        
        if(idx == -1) {
            isSubmarine = false;
            break;
        }
    }

    if(isSubmarine) cout << "SUBMARINE";
    else cout << "NOISE";
}