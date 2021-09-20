#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

long long Cal(long long a, long long b ,char op)
{
    switch(op)
    {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
        case '*':
            return a*b;
            break;
    }
    return 0;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> op;

    stringstream ss(expression);

    // 문자열 분리
    char token;
    string temp = "";
    while(ss >> token)
    {
        if(token >= '0' && token <= '9')
            temp += token;
        else
        {
            num.push_back(stoi(temp));
            temp = "";
            op.push_back(token);
        }
    }
    num.push_back(stoi(temp));

    vector<char> ops = {'+', '-', '*'};
    sort(ops.begin(), ops.end());
    // 연산자 우선순위
    do {
        vector<long long> numbers = num;
        vector<char> operators = op;

        while(true)
        {
            if(find(operators.begin(), operators.end(),ops[0]) == operators.end()) break;
            int idx = find(operators.begin(), operators.end(), ops[0]) - operators.begin();
            long long cal = Cal(numbers[idx],numbers[idx+1],operators[idx]);
            operators.erase(operators.begin()+idx);
            numbers.erase(numbers.begin()+idx);
            numbers[idx] = cal;
        }

        while(true)
        {
            if(find(operators.begin(), operators.end(), ops[1]) == operators.end()) break;
            int idx = find(operators.begin(), operators.end(), ops[1]) - operators.begin();
            long long cal = Cal(numbers[idx], numbers[idx+1],operators[idx]);
            operators.erase(operators.begin()+idx);
            numbers.erase(numbers.begin()+idx);
            numbers[idx] = cal;
        }

        while(true)
        {
            if(find(operators.begin(), operators.end(), ops[2]) == operators.end()) break;
            int idx = find(operators.begin(), operators.end(), ops[2]) - operators.begin();
            long long cal = Cal(numbers[idx], numbers[idx+1],operators[idx]);
            operators.erase(operators.begin()+idx);
            numbers.erase(numbers.begin()+idx);
            numbers[idx] = cal;
        }

        answer = max(answer, abs(numbers[0]));
    }while(next_permutation(ops.begin(), ops.end()));

    return answer;
}
