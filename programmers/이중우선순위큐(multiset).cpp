#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer(2,0);

    multiset<int> ms;

    for(int i = 0; i < operations.size(); i++)
    {
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));

        if(op == 'I')
        {
            ms.insert(num);
        }
        else
        {
            if(ms.empty()) continue;
            if(num == 1) ms.erase(--ms.end());
            else if(num == -1) ms.erase(ms.begin());
        }
    }

    if(ms.empty()) return answer;

    answer[0] = *(--ms.end());
    answer[1] = *(ms.begin());

    return answer;
}
