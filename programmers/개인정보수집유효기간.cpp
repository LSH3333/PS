#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// yyyy.mm.dd
int ConvertDateToNum(const string &date) {
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5,2));
    int d = stoi(date.substr(8));
    return (y * 28 * 12) + (m * 28) + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int todayInt = ConvertDateToNum(today);
    unordered_map<char,int> mp;

    for(auto term : terms) {
        char t = term.front();
        int day = stoi(term.substr(2));
        mp[t] = day * 28;
    }

    int index = 1;
    for (const auto &privacy: privacies) {
        int date = ConvertDateToNum(privacy.substr(0, 10));
        char term = privacy.back();

        int valid = date + mp[term];
        if(valid <= todayInt) {
            answer.push_back(index);
        }
        index++;
    }

    return answer;
}

int main() {
    string today = "2022.05.19";
    vector<string> terms = {"A 6", "B 12", "C 3"};
    vector<string> privacies = {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"};
    solution(today, terms, privacies);
}