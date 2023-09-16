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
    unordered_map<string,int> mp;
    string S, E, Q;
    cin >> S >> E >> Q;
    int s = StringTimeToIntTime(S);
    int e = StringTimeToIntTime(E);
    int q = StringTimeToIntTime(Q);

    string time , name;
    while (cin >> time >> name) {
        int intTime;
        intTime = StringTimeToIntTime(time);

        if (intTime <= s || (intTime >= e && intTime <= q)) {
            mp[name]++;
        }
    }

    int answer = 0;
    for (const auto &item: mp) {
        if(item.second >= 2) {
            answer++;
        }
    }


}