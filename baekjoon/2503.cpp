#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
int ans = 0;

vector<string> asked;
vector<pair<int,int>> sb;
vector<int> comb;

int nums[9] = {1,2,3,4,5,6,7,8,9};
int nums_idx[9] = {1,1,1,0,};

bool Calculate() {
    for(int i = 0; i < asked.size(); i++) {
        int strike = 0;
        int ball = 0;
        // strike, ball 판별
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(comb[j] == asked[i][k]-'0') {
                    if(j == k)
                        strike++;
                    else
                        ball++;
                    break;
                }
            }
        }

        if((strike != sb[i].first) || (ball != sb[i].second))
            return false;
    }
    return true;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string _asked = "";
        cin >> _asked;
        asked.push_back(_asked);

        int strike, ball;
        cin >> strike >> ball;
        sb.push_back({strike, ball});
    }

    // 조합
    do {
        for(int i = 0; i < 9; i++) {
            if(nums_idx[i] == 1) {
                comb.push_back(nums[i]);
            }
        }
        // 조합에 대한 순열
        do {
            if(Calculate())
                ans++;
        } while(next_permutation(comb.begin(), comb.end()));

        comb.clear();
    } while(prev_permutation(nums_idx, nums_idx+9));

    cout << ans;
}