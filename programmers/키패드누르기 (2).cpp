#include <iostream>
#include <string>
#include <vector>
using namespace std;

int CalDistance(int hand, int num)
{
    if(num == 2)
    {
        if(hand == 2) return 0;
        if(hand == 1 || hand == 3 || hand == 5) return 1;
        if(hand == 4 || hand == 6 || hand == 8) return 2;
        if(hand == 7 || hand == 9 || hand == 0) return 3;
        if(hand == 10 || hand == 11) return 4;
    }
    if(num == 5)
    {
        if(hand == 5) return 0;
        if(hand == 4 || hand == 6 || hand == 2 || hand == 8) return 1;
        if(hand == 1 || hand == 3 || hand == 7 || hand == 9 || hand == 0) return 2;
        if(hand == 10 || hand == 11) return 3;
    }
    if(num == 8)
    {
        if(hand == 8) return 0;
        if(hand == 5 || hand == 7 || hand == 9 || hand == 0) return 1;
        if(hand == 4 || hand == 2 || hand == 6 || hand == 10 || hand == 11) return 2;
        if(hand == 1 || hand == 3) return 3;
    }
    if(num == 0)
    {
        if(hand == 0) return 0;
        if(hand == 10 || hand == 11 || hand == 8) return 1;
        if(hand == 7 || hand == 5 || hand == 9) return 2;
        if(hand == 4 || hand == 2 || hand == 6) return 3;
        if(hand == 1 || hand == 3) return 4;
    }
}

string solution(vector<int> numbers, string hand)
{
    string ans;
    // *:10, #:11
    int L = 10, R = 11;
    for(auto num : numbers)
    {
        if(num == 1 || num == 4 || num ==  7)
        {
            ans += 'L';
            L = num;
        }
        else if(num == 3 || num == 6 || num == 9)
        {
            ans += 'R';
            R = num;
        }
        else
        {
            int LDist = CalDistance(L, num);
            int RDist = CalDistance(R, num);
            if(LDist < RDist)
            {
                ans += 'L';
                L = num;
            }
            else if(LDist > RDist)
            {
                ans += 'R';
                R = num;
            }
            else
            {
                if(hand == "left") { ans += 'L'; L = num;}
                else {ans += 'R'; R = num; }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
    string hand = "right";
    solution(numbers, hand);
}
