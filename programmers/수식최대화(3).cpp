#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<char, int> order =
        {
                {'+', 0}, {'-', 1}, {'*', 2}
        };

void DivideExpression(string exp, vector<long long> &num, vector<int> &op)
{
    string number;
    for(auto x : exp)
    {
        if(x >= '0' && x <= '9')
        {
            number.push_back(x);
        }
        else // op
        {
            num.push_back(stoi(number));
            number.clear();
            op.push_back(order[x]);
        }
    }
    num.push_back(stoi(number));
}

long long Cal(int op, long long n1, long long n2)
{
    switch(op)
    {
        case 0:
            return n1 + n2;
        case 1:
            return n1 - n2;
        case 2:
            return n1 * n2;
    }
    return 0;
}

long long solution(string expression)
{
    vector<long long> _num;
    vector<int> _op;
    DivideExpression(expression, _num, _op);

    long long answer = 0;
    vector<int> per = {0, 1, 2};
    do
    {
        vector<long long> num = _num;
        vector<int> op = _op;
//        cout << "per: ";
//        for(auto x : per) cout << x << ' '; cout << endl;

        // 3개의 연산자에 대하여
        for(int i = 0; i < 3; i++)
        {
            int target = per[i];
            int idx = 0;
            while(idx < op.size() && !op.empty() && !num.empty())
            {
                if(op[idx] == target)
                {
//                    for(auto x : num) cout << x << ' '; cout << endl;
//                    for(auto x : op) cout << x << ' '; cout << endl;
                    num[idx] = Cal(target, num[idx], num[idx+1]);
                    op.erase(op.begin()+idx);
                    num.erase(num.begin()+idx+1);
                    idx = -1;
                }
                idx++;
            }
        }
        answer = max(answer, abs(num.front()));
    } while(next_permutation(per.begin(), per.end()));


//    cout << answer;
    return answer;
}

int main()
{
    string expression = "100-200*300-500+20";
    solution(expression);
}