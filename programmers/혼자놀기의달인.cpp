#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool openedBox[110];

int OpenBox(int i, const vector<int> &cards, int depth) {
    if(openedBox[i]) {
        return depth;
    }

    openedBox[i] = true;
    int card = cards[i];
    return OpenBox(card, cards, depth+1);
}

int solution(vector<int> cards) {
    cards.insert(cards.begin(), 0);
    int answer = 0;
    vector<int> groups;

    for(int i = 1; i < cards.size(); i++) {
        if(!openedBox[i]) {
            int depth = OpenBox(i, cards, 0);
            groups.push_back(depth);
        }
    }

    sort(groups.begin(), groups.end(), greater<>());

    if(groups.size() == 1) {
        answer = 0;
    } else {
        answer = groups[0] * groups[1];
    }


    return answer;
}

int main() {
    vector<int> cards = {8, 6, 3, 7, 2, 5, 1, 4};
    solution(cards);
}