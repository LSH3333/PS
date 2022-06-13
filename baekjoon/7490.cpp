#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> answers;

// numbers, ops로 계산 후 결과가 0이라면 answers 벡터에 정답이 되는 문자열 푸쉬
void Cal(const vector<int> &numbers, const vector<int> &ops)
{
    // 공백 처리
    string str;
    for(int i = 0; i < ops.size(); i++)
    {
        str += to_string(numbers[i]);

        int op = ops[i];
        if(op == 0) str += '+';
        else if(op == 1) str += '-';
    }
    str += to_string(numbers.back());

    // 숫자, 연산자 분리
    vector<int> n, op;
    stringstream ss(str);
    int token;
    while(ss >> token) n.push_back(abs(token));

    for(auto x : str)
    {
        if(x >= '0' && x <= '9') continue;
        if(x == '+') op.push_back(0);
        else if(x == '-') op.push_back(1);
    }

    // 계산
    int sum = n.front();
    for(int i = 0; i < op.size(); i++)
    {
        if(op[i] == 0) sum += n[i+1];
        else if(op[i] == 1) sum -= n[i+1];
    }

    // 합이 0이라면 answers 벡터에 수식 추가
    if(sum == 0)
    {
        string answer;
        for(int i = 0; i < ops.size(); i++)
        {
            answer += to_string(numbers[i]);
            if(ops[i] == 0) answer += '+';
            else if(ops[i] == 1) answer += '-';
            else answer += ' ';
        }
        answer += to_string(numbers.back());

        answers.push_back(answer);
    }
}

void dfs(const vector<int> &numbers, vector<int> &ops, int N)
{
    if(ops.size() == N-1)
    {
        Cal(numbers, ops);
        return;
    }

    for(int i = 0; i < 3; i++)
    {
        ops.push_back(i);
        dfs(numbers, ops, N);
        ops.pop_back();
    }
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<int> numbers(N); // 수열
        vector<int> ops; // 연산
        for(int i = 1; i <= N; i++) numbers[i-1] = i;

        dfs(numbers, ops, N);

        sort(answers.begin(), answers.end());
        for(auto x : answers) cout << x << '\n';

        cout << '\n';
        answers.clear();
    }


}
