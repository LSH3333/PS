#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Hanoi(int n, int a, int b, int c, vector<vector<int>> &answer) {
    if(n == 1) {
        answer.push_back({a, c});
        return;
    }
    // a ? ?? n-1 ?? a ?? c ??? b ?
    Hanoi(n - 1, a, c, b, answer);
    // a? ???? ??? c ?
    answer.push_back({a, c});
    // b ? ?? n-1 ?? a ?? c ?
    Hanoi(n - 1, b, a, c, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    Hanoi(n, 1, 2, 3, answer);

    return answer;
}

int main() {
    const vector<vector<int>> &vector = solution(4);
    cout << endl;

}