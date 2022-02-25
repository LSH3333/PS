#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<long long> numbers;
vector<int> operators;

void Divide(string expression)
{
    for(int i = 0; i < expression.size(); i++)
    {
        char c = expression[i];
        if(c >= '0' && c <= '9') continue;
        if(c == '+') operators.push_back(1);
        else if(c == '-') operators.push_back(2);
        else if(c == '*') operators.push_back(3);
        expression[i] = ' ';
    }

    stringstream ss(expression);
    string token;
    while(ss >> token) numbers.push_back(stoi(token));
}

long long Cal(vector<int> per, vector<long long> _numbers, vector<int> _operators)
{
    for(auto target : per)
    {
        while(true)
        {
            // target 찾으면 true
            bool trigger = false;
            for(int i = 0; i < _operators.size(); i++)
            {
                if(_operators[i] != target) continue;
                trigger = true;
                // +
                if(target == 1) _numbers[i] = _numbers[i] + _numbers[i+1];
                // -
                else if(target == 2) _numbers[i] = _numbers[i] - _numbers[i+1];
                // *
                else _numbers[i] = _numbers[i] * _numbers[i+1];
                _operators.erase(_operators.begin()+i);
                _numbers.erase(_numbers.begin()+i+1);
                break;
            }
            if(!trigger) break;
        }
    }
    return _numbers.front();
}

long long solution(string expression)
{
    // 1:+, 2:-. 3:*
    bool tmp[4] = {false,};
    for(int i = 0; i < expression.size(); i++)
    {
        if(expression[i] == '+') tmp[1] = true;
        else if(expression[i] == '-') tmp[2] = true;
        else if(expression[i] == '*') tmp[3] = true;
    }

    Divide(expression);

    long long answer = 0;
    vector<int> op;
    for(int i = 1; i < 4; i++) if(tmp[i]) op.push_back(i);
    sort(op.begin(), op.end());

    do {
        long long res = abs(Cal(op, numbers, operators));
        answer = max(answer, res);
    } while(next_permutation(op.begin(), op.end()));
    
    return answer;
}

int main()
{
    string expression = "50*6-3*2";
    solution(expression);
}