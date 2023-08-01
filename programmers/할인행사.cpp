#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <deque>
using namespace std;

int totalWantNum;

bool Check(map<string,int> &m, const vector<string> &want, const vector<int> &number) {
    for(int i = 0; i < want.size(); i++) {
        // item ? wantNum ? ???
        string item = want[i];
        int wantNum = number[i];

        if(m[item] < wantNum) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> m;
    deque<string> dq;

    for(auto x : number) {
        totalWantNum += x;
    }

    // ?? ??? ??
    for(int i = 0; i < totalWantNum; i++) {
        dq.push_back(discount[i]);
        m[discount[i]]++;
    }


    int i = totalWantNum-1;
    while (i < discount.size()) {
        // ?? ??
        if (Check(m, want, number)) {
            answer++;
        }

        if(i+1 == discount.size()) break;

        // ??? ??
        m[dq.front()]--;
        dq.pop_front();
        // ??? ??
        m[discount[i+1]]++;
        dq.push_back(discount[i+1]);
        i++;
    }


    return answer;
}

int main() {
    vector<string> want = {"banana", "apple", "rice", "pork", "pot"};
    vector<int> number = {3, 2, 2, 2, 1};
    vector<string> discount = {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice",
                               "pot", "banana", "apple", "banana"};
    cout << solution(want, number, discount);
}