#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> earn;

void dfs(string node, int amount)
{
    if(node == "-") return;
    if(amount == 0) return;

    int give = amount / 10;
    int earned = amount - give;
    earn[node] += earned;
    dfs(parent[node], give);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;

    for(int i = 0; i < enroll.size(); i++)
    {
        parent[enroll[i]] = referral[i];
    }

    for(int i = 0; i < seller.size(); i++)
    {
        dfs(seller[i], amount[i] * 100);
    }

    for(auto x : enroll)
        answer.push_back(earn[x]);

    return answer;
}

int main()
{
    vector<string> enroll =
            {
                    "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"
            };
    vector<string> referral =
            {
                    "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"
            };
    vector<string> seller =
            {
                    "young", "john", "tod", "emily", "mary"
            };
    vector<int> amount =
            {
                    12, 4, 2, 5, 10
            };
    solution(enroll, referral, seller, amount);
}