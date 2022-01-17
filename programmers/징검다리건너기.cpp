#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 2000000000;

    int maxN = 0;
    for(int i = 0; i < k; i++) maxN = max(stones[i], maxN);
    answer = maxN;

    for(int i = k-1; i < stones.size(); i++)
    {
        if(stones[i-k] == maxN)
        {
            maxN = 0;
            for(int j = i; j > i-k; j--)
            {
                maxN = max(stones[j], maxN);
            }
        }
        else if(stones[i] > maxN)
        {
            maxN = stones[i];
        }
        if(maxN < answer) answer = maxN;
//        cout << "i: " << i << ' ' << maxN << endl;
    }
//    cout << answer;
    return answer;
}

int main()
{
    vector<int> stones = {2,4,5,3,2,1,4,2,5,1};
    solution(stones, 3);
}