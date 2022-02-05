#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for(int i = 0; i < prices.size(); i++)
    {
        int cnt = 0;
        for(int j = i+1; j < prices.size(); j++)
        {
            if(prices[i] <= prices[j]) cnt++;
            else {cnt++; break;}
        }

        answer.push_back(cnt);
    }

    answer.back() = 0;
    return answer;
}

int main()
{
    vector<int> prices = {1, 2, 3, 2, 3, 1};
    vector<int> prices2 = {1,2,3,2,3};
    solution(prices2);
}