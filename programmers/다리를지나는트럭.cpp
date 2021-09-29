#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> trucks;
    for(auto x : truck_weights) trucks.push(x);

    queue<int> q;
    for(int i = 0; i < bridge_length; i++) q.push(0);
    int curWeight = 0;

    while(!trucks.empty())
    {
        // q의 front에 있는 트럭 다리에서 내림
        curWeight -= q.front();
        q.pop();

        if(curWeight + trucks.front() > weight) q.push(0);
        else
        {
            int nextTruck = trucks.front();
            q.push(nextTruck); trucks.pop();
            curWeight += nextTruck;
        }

        answer++;
    }
    answer += bridge_length;

    return answer;
}
