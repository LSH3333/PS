#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long answer;
string input;


void dfs(int idx, int consonant, int vowel, bool isL, long long result) {
    if(consonant == 3 || vowel == 3) {
        return;
    }
    if (idx == input.size()) {
        if (isL) {
            answer += result;
        }
        return;
    }

    if (input[idx] == '_') {
        // ??
        dfs(idx+1, 0, vowel+1, isL, result*5);
        // L
        dfs(idx + 1, consonant + 1, 0, true, result);
        // ??
        dfs(idx + 1, consonant + 1, 0, isL, result * 20);
    }
    else {
        char c = input[idx];
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            dfs(idx + 1, 0, vowel + 1, isL, result);
        }
        else if(c == 'L') {
            dfs(idx+1, consonant+1, 0, true, result);
        }
        else {
            dfs(idx + 1, consonant + 1, 0, isL, result);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> input;

    dfs(0, 0, 0, false, 1);

    cout << answer;

}