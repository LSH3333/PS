#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long CalVSum(const vector<int> &v) {
    long long sum = 0;
    for(auto x : v) {
        sum += x;
    }
    return sum;
}

queue<int> MakeQ(const vector<int> &v) {
    queue<int> q;
    for(auto x : v) {
        q.push(x);
    }
    return q;
}

void PopAndInsert(queue<int> &from, queue<int> &to, long long &fromSum, long long &toSum) {
    int n = from.front();
    from.pop();
    to.push(n);
    fromSum -= n;
    toSum += n;
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long q1sum = CalVSum(queue1);
    long long q2sum = CalVSum(queue2);

    queue<int> q1 = MakeQ(queue1);
    queue<int> q2 = MakeQ(queue2);

    while (true) {
        if (q1.empty() || q2.empty() ||
            answer == (queue1.size() + queue2.size()) * 2) {
            answer = -1;
            break;
        }

        if (q1sum == q2sum) {
            break;
        } else if (q1sum < q2sum) {
            PopAndInsert(q2, q1, q2sum, q1sum);
        }
        else {
            PopAndInsert(q1, q2, q1sum, q2sum);
        }
        answer++;
    }


    return answer;
}

int main() {
    vector<int> q1 = {3,2,7,2}, q2 = {4,6,5,1};
    cout << solution(q1, q2);
}