#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    map<string,int> jewels;
    for(auto gem : gems) jewels[gem]++;
    int jewelsSize = jewels.size();
    jewels.clear();

    int l=0, r=0;
    for(int i = 0; i < gems.size(); i++)
    {
        jewels[gems[i]]++;
        if(jewels.size() == jewelsSize) { r = i; break;}
    }

    answer.push_back(0);
    answer.push_back(r);
    int min = r - l;
    while(r < gems.size())
    {
        string gem = gems[l];
        jewels[gem]--;
        l++;

        if(jewels[gem] == 0)
        {
            r++;
            for(; r < gems.size(); r++)
            {
                jewels[gems[r]]++;
                if(gems[r] == gem) break;
            }
            if(r >= gems.size()) break;
        }
        if(r-l < min)
        {
            min = r - l;
            answer[0] = l;
            answer[1] = r;
        }
    }

    answer[0]++; answer[1]++;
    return answer;
}


int main()
{
    vector<string> gems = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
    solution(gems);

}