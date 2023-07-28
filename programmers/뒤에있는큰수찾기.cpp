#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    // min heap
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = (int)numbers.size()-1; i >= 0; i--) {
        int n = numbers[i];

        if(pq.empty()) {
            pq.push(n);
            answer[i] = -1;
        }
        else {
            while (!pq.empty() && pq.top() <= n) {
                pq.pop();
            }

            if(pq.empty()) {
                answer[i] = -1;
            } else {
                answer[i] = pq.top();
            }
            pq.push(n);
        }
    }

    return answer;
}

int main() {
    vector<int> numbers = {2, 3, 3, 5};
    solution(numbers);

}