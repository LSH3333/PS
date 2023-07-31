#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000

int d1[MAX + 1];
int d2[MAX + 1];

int solution(vector<int> sticker) {
    int answer = 0;
    if(sticker.size() == 1) {
        return sticker.front();
    }

    // ??? ?? ??
    for(int i = 0; i < (int)sticker.size()-1; i++) {
        int a=0, b=0;
        if(i-2 >= 0) {
            a = d1[i-2] + sticker[i];
        }else {
            a = sticker[i];
        }
        if(i-1 >= 0) {
            b = d1[i-1];
        }

        d1[i] = max(a,b);
        answer = max(answer, d1[i]);
    }

    // ? ?? ??
    for(int i = 1; i < (int)sticker.size(); i++) {
        int a=0, b=0;
        if(i-2 >= 1) {
            a = d2[i-2] + sticker[i];
        }else {
            a = sticker[i];
        }
        if(i-1 >= 1) {
            b = d2[i-1];
        }

        d2[i] = max(a,b);
        answer = max(answer, d2[i]);
    }


    return answer;
}

int main() {
    vector<int> sticker = {1};
    cout << solution(sticker);
}