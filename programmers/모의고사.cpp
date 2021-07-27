#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 특정 수포자의 정답수 리턴
int Calculate(vector<int> answers, vector<int> target)
{
    int idx = 0;
    int cnt = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        if(target[idx] == answers[i]) cnt++;

        if(idx == target.size()-1)
            idx = -1;

        idx++;
    }
    return cnt;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    vector<int> a = {1,2,3,4,5};
    vector<int> b = {2,1,2,3,2,4,2,5};
    vector<int> c = {3,3,1,1,2,2,4,4,5,5};

    int a_cnt = Calculate(answers, a);
    int b_cnt = Calculate(answers, b);
    int c_cnt = Calculate(answers, c);
    
    vector<pair<int,int>> score;
    score.push_back({a_cnt, 1});
    score.push_back({b_cnt, 2});
    score.push_back({c_cnt, 3});

    // 점수기준 내림차순 정렬
    sort(score.begin(), score.end(), greater<>());

    // 내림차순 정렬이기 때문에 score[0].first에 가장 큰 점수가 저장됨
    // [1],[2]에 있는 점수가 가장 큰 점수와 값이 다르다면 pop
    if(score[0].first != score[2].first) score.pop_back();
    if(score[0].first != score[1].first) score.pop_back();

    for(auto x : score)
    {
        answer.push_back(x.second);
    }

    sort(answer.begin(), answer.end());

    return answer;

}