#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 1000000

int N;
bool mark[MAX+1];

void Count(int len, const vector<int> &elements) {
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += elements[i];
    }
    mark[sum] = true;

    for(int i = 1; i < N; i++) {
        // left
        sum -= elements[i-1];
        // right
        int right = i + len - 1;
        if(right >= N) {
            sum += elements[right - N];
        }
        else {
            sum += elements[right];
        }

        mark[sum] = true;
    }
}

int solution(vector<int> elements) {
    int answer = 0;
    N = (int)elements.size();

    for(int len = 1; len <= N; len++) {
        Count(len, elements);
    }

    for(int i = 1; i <= MAX; i++) {
        if(mark[i]) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<int> elements = {7, 9, 1, 1, 4};
    cout << solution(elements);
}