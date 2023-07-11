#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> inputs;

bool Check(const vector<char> &comb) {
    int vowels=0, consonants=0;
    for(const auto &x : comb) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
            vowels++;
        } else {
            consonants++;
        }
    }

    if(vowels < 1 || consonants < 2) return false;
    else return true;
}

void makeComb(int idx, int depth, vector<char> &comb) {
    if(depth == L) {
        if (Check(comb)) {
            for(auto x : comb) {
                cout << x;
            } cout << '\n';
        }
        return;
    }

    for (int i = idx; i < inputs.size(); i++) {
        comb.push_back(inputs[i]);
        makeComb(i+1, depth+1, comb);
        comb.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> L >> C;
    for(int i = 0; i < C; i++) {
        char c; cin >> c;
        inputs.push_back(c);
    }
    sort(inputs.begin(), inputs.end());

    vector<char> comb;
    makeComb(0, 0, comb);
}