#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int FindLastZeroIdx(const string &res) {
    int lastZeroIdx = -1;
    for(int i = (int)res.size()-1; i >= 0; i--) {
        if(res[i] == '0') {
            lastZeroIdx = i;
            break;
        }
    }
    return lastZeroIdx;
}

string Cal(const string &s) {
    string res, insertStr;

    for(int i = 0; i < s.size(); i++) {
        char x = s[i];

        res.push_back(x);
        if ((int)res.size()-3 >= 0 && res.substr(res.size() - 3) == "110") {
            insertStr += "110";
            // ?? "110" ??
            res.pop_back();
            res.pop_back();
            res.pop_back();
        }
    }

    // find last zero index from res
    int lastZeroIdx = FindLastZeroIdx(res);

    // insert
    res.insert(lastZeroIdx+1, insertStr);


    return res;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for(const auto &x : s) {
        answer.push_back(Cal(x));
    }


    return answer;
}

int main() {
    vector<string> s = {"1110", "100111100", "0111111010"};
    const vector<string> &vector = solution(s);
    for (auto x: vector) {
        cout << x << endl;
    }
}