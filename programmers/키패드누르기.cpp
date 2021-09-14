#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> dis(15);

string solution(vector<int> numbers, string hand) {
    string answer = "";

    hand = hand == "right" ? "R" : "L";
    // [10]=*, [11]=#
    dis[2] = {3,1,0,1,2,1,2,3,2,3,4,4};
    dis[5] = {2,2,1,2,1,0,1,2,1,2,3,3};
    dis[8] = {1,3,2,3,2,1,2,1,0,1,2,2};
    dis[0] = {0,4,3,4,3,2,3,2,1,2,1,1};

    int l=10,r=11;
    for(int i = 0; i < numbers.size(); i++)
    {
        // left
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer.push_back('L');
            l = numbers[i];
        }
            // right
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer.push_back('R');
            r = numbers[i];
        }
            // mid
        else
        {
            int Ldis = dis[numbers[i]][l];
            int Rdis = dis[numbers[i]][r];

            if(Ldis == Rdis)
            {
                answer += hand;
                if(hand == "R") r = numbers[i];
                else l = numbers[i];
            }
            else if(Ldis < Rdis)
            {
                answer += "L";
                l = numbers[i];
            }
            else
            {
                answer += "R";
                r = numbers[i];
            }
        }
    }

    return answer;
}
