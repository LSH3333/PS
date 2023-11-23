#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> mp;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    for(auto gem : gems) {
        mp[gem] = 0;
    }

    int ansL = 0, ansR = 200000, collected = 0;
    int l = 0, r = 0;
    while (r <= gems.size()) {
        // ?? ?? ??
        if (collected == mp.size()) {
            // ? ??
            if(ansR-ansL > (r-1) - l) {
                ansR = r-1; ansL = l;
            }

            mp[gems[l]]--;
            if(mp[gems[l]] == 0) collected--;
            l++;
        }
        else {
            // r ??? ?? ??
            if (r == gems.size()) {
                break;
            }
            else {
                if(mp[gems[r]] == 0) collected++;
                mp[gems[r]]++;
                r++;
            }
        }
    }

//    cout << ansL << ' ' << ansR;
    answer.push_back(ansL+1);
    answer.push_back(ansR+1);
    return answer;
}

int main() {
//    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    vector<string> gems = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};

    solution(gems);

}