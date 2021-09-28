#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    for(int minus = 0; minus < numbers.size(); minus++)
    {
        vector<int> mark(numbers.size(), 1);
        for(int i = 0; i <= minus; i++) mark[i] = -1;

        do {
            int sum = 0;
            for(int i = 0; i < numbers.size(); i++)
            {
                if(mark[i] == -1) sum += numbers[i] * -1;
                else sum += numbers[i];
            }
            if(sum == target) answer++;
        }while(next_permutation(mark.begin(), mark.end()));
    }

    return answer;
}
