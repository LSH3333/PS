#include <vector>
#include <algorithm>
using namespace std;

int a[5] = {1,2,3,4,5};
int b[8] = {2,1,2,3,2,4,2,5};
int c[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    int a_score=0, b_score=0, c_score=0;
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == a[i % 5]) a_score++;
        if(answers[i] == b[i % 8]) b_score++;
        if(answers[i] == c[i % 10]) c_score++;
    }

    int max_score = max(max(a_score, b_score), c_score);

    if(a_score == max_score) answer.push_back(1);
    if(b_score == max_score) answer.push_back(2);
    if(c_score == max_score) answer.push_back(3);

    return answer;

}