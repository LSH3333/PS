#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

struct Node
{
    bool filled = false;
    long long num;
    long long parent = -1;
};

map<long long, Node> m;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for(auto number : room_number)
    {
        // 빈 방일 경우
        if(m.find(number) == m.end())
        {
            Node node;
            node.filled = true;
            node.num = number;
            node.parent = number+1;
            m[number] = node;
            answer.push_back(number);
        }
        // 방이 이미 차있는 경우
        else
        {
            // 비어있는 방 찾음
            long long n = number;
            vector<long long> paths; // 방문한 방 넘버 기록
            while(true)
            {
                if(!m[n].filled) break;
                paths.push_back(n);
                n = m[n].parent;
            }
            // check in
            Node node;
            node.filled = true;
            node.num = n;
            node.parent = n+1;
            m[n] = node;
            answer.push_back(n);

            // 방문한 방들 부모노드 수정
            for(auto x : paths) m[x].parent = n + 1;
        }
    }

    return answer;
}
