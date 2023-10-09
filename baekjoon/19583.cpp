/**
* shinyo17, kimchist, swoon, kheee512, Green55,
 * kimchist, swoon, kheee512
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int StringTimeToIntTime(const string &strTime) {
    string h = strTime.substr(0,2);
    string m = strTime.substr(3);
    return stoi(h) * 60 + stoi(m);
}

int main() {
    unordered_map<string,int> mp1, mp2;
    string S, E, Q;
    cin >> S >> E >> Q;
    int s = StringTimeToIntTime(S);
    int e = StringTimeToIntTime(E);
    int q = StringTimeToIntTime(Q);

    while (true) {
        string time , name;
        int intTime;
        cin >> time;
        if(cin.eof()) break;
        cin >> name;
        intTime = StringTimeToIntTime(time);

        if(intTime >= 0 && intTime <= s) {
            mp1[name]++;
        }
        if (intTime >= e && intTime <= q) {
            mp2[name]++;
        }
    }

    int answer = 0;
    for (const auto &item: mp1) {
        if(mp2[item.first] > 0) {
            answer++;
        }
    }

    cout << answer;

}