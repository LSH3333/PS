#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct Tree
{
    string name;
    Tree* parent;
    long long money;
};

unordered_map<string, Tree> m;

void Cal(string name, int amount)
{
    if(amount == 0) return;
    int give = amount / 10;
    if(m[name].parent == NULL)
    {
        m[name].money += amount - give;
        return;
    }
    m[name].money += amount - give;
    Cal(m[name].parent->name, give);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for(int i = 0; i < enroll.size(); i++)
    {
        Tree tmp;
        tmp.name = enroll[i];
        tmp.money = 0;
        if(referral[i] == "-") tmp.parent = NULL;
        else tmp.parent = &m[referral[i]];
        m[enroll[i]] = tmp;
    }

    // 이득 계산
    for(int i = 0; i < seller.size(); i++) Cal(seller[i], amount[i] * 100);

    for(int i = 0; i < enroll.size(); i++) answer.push_back(m[enroll[i]].money);

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