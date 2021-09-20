#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A','C','F','J','M','N','R','T'};

    do {
        bool possible = true;
        for(int i = 0; i < n; i++)
        {
            int friend1Idx = find(friends.begin(), friends.end(), data[i][0]) - friends.begin();
            int friend2Idx = find(friends.begin(), friends.end(), data[i][2]) - friends.begin();
            char op = data[i][3];
            int targetGap = data[i][4]-'0';
            int gap = abs(friend1Idx - friend2Idx)-1;

            switch(op)
            {
                case '=':
                    if(gap != targetGap) possible = false;
                    break;
                case '<':
                    if(gap >= targetGap) possible = false;
                    break;
                case '>':
                    if(gap <= targetGap) possible = false;
                    break;
            }
            if(!possible) break;
        }
        if(possible) answer++;
    }while(next_permutation(friends.begin(), friends.end()));

    cout << answer;

    return answer;
}