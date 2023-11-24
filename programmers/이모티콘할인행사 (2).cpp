#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int rates[10];
vector<pair<int,int>> answers;

bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

void Cal(const vector<vector<int>> &users, const vector<int> &emoticons) {
    int subscriber = 0, earned = 0;
    for(auto &user : users) {
        // user ? buyRate ???? ???? ??
        // ?? ?? ?, buyPrice ???? ?? ??, ??? ??
        int buyRate = user[0], buyPrice = user[1];

        int totalPrice = 0;
        // user ? buyRate ???? ???? ??
        for(int i = 0; i < emoticons.size(); i++) {
            if (rates[i] >= buyRate) { // ??
                totalPrice += (emoticons[i] / 100) * (100 - rates[i]);
            }
        }
        // buyPrice ???? ?? ??, ??? ??
        if (totalPrice >= buyPrice) {
            subscriber++;
        } else {
            earned += totalPrice;
        }
    }

    answers.push_back({subscriber, earned});
}

void SetRate(int depth, const vector<vector<int>> &users, const vector<int> &emoticons) {
    if (depth == emoticons.size()) {
//        cout << "rate = \n";
//        for(int i = 0; i < emoticons.size(); i++) {
//            cout << rates[i] << ' ';
//        } cout<<endl;
        Cal(users, emoticons);
        return;
    }

    for(int rate = 10; rate <= 40; rate += 10) {
        rates[depth] = rate;
        SetRate(depth + 1, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    SetRate(0, users, emoticons);
    sort(answers.begin(), answers.end(), cmp);
//    for(auto x : answers) {
//        cout << x.first << ' ' << x.second << endl;
//    }
    answer.push_back(answers.front().first);
    answer.push_back(answers.front().second);
    return answer;
}

int main() {
    vector<vector<int>> users = {
            {40, 10000},
            {25, 10000}
    };
    vector<int> emoticons = {
            7000, 9000
    };
    solution(users, emoticons);
}