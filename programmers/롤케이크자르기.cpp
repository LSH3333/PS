#include <string>
#include <vector>
#include <iostream>

using namespace std;

int older[10001], younger[10001];

int solution(vector<int> topping) {
    int answer = 0;
    int olderCnt = 0, youngerCnt = 0;

    // ??? ?? ??? ??
    for(auto x : topping) {
        if(younger[x] == 0) {
            youngerCnt++;
        }
        younger[x]++;
    }

    // ?? ?? ????
    for(auto x : topping) {
        if(older[x] == 0) {
            olderCnt++;
        }
        older[x]++;

        younger[x]--;
        if(younger[x] == 0) {
            youngerCnt--;
        }

        if(olderCnt == youngerCnt) {
            answer++;
        }
    }


    return answer;
}

int main() {
    vector<int> topping = {1, 2, 3, 1, 4};
    cout << solution(topping);
}