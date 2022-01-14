#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 2000000000;

    for(int i = k-1; i < stones.size(); i++)
    {
        int maxN = 0;
        for(int j = i; j > i-k; j--)
        {
             maxN = max(stones[j], maxN);
        }
        answer = min(answer, maxN);
    }

    return answer;
}

int main()
{
    vector<int> stones =
            {
                    2, 4, 5, 3, 2, 1, 4, 2, 5, 1
            };
    solution(stones, 3);
}