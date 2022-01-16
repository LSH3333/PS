#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// lower_bound를 이용?
int solution(vector<int> stones, int k) {
    int answer = 2000000000;

    int tmp = 0;
    for(int i = 0; i < k; i++)
    {
        tmp = max(tmp, stones[i]);
    }

    answer = tmp;
    for(int i = k; i < stones.size(); i++)
    {
        if(max(tmp,stones[i]) == stones[i-k])
        {
            tmp = 0;
            for(int j = i; j > i-k; j--)
            {
                tmp = max(tmp, stones[j]);
            }
        }
        else
        {
            tmp = max(tmp, stones[i-k+1]);
        }
        answer = min(answer, tmp);
    }

    return answer;
}


int main()
{

}