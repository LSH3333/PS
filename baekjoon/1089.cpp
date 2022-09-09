#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
char A[5][50];
char Numbers[][50] =
        {
                "###...#.###.###.#.#.###.###.###.###.###",
                "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
                "#.#...#.###.###.###.###.###...#.###.###",
                "#.#...#.#.....#...#...#.#.#...#.#.#...#",
                "###...#.###.###...#.###.###...#.###.###"
        };


void SepNums(vector<string> &floors)
{
    for(int cIdx = 0; cIdx < 4*N-1; cIdx+=4)
    {
        string str;
        for(int r = 0; r < 5; r++)
        {
            for(int c = cIdx; c < cIdx+3; c++)
            {
                str.push_back(A[r][c]);
            }
        }
        floors.push_back(str);
    }
}

void SaveNums(vector<string> &nums)
{
    for(int cIdx = 0; cIdx < 39; cIdx+=4)
    {
        string str;
        for(int r = 0; r < 5; r++)
        {
            for(int c = cIdx; c < cIdx+3; c++)
            {
                str.push_back(Numbers[r][c]);
            }
        }
        nums.push_back(str);
    }
}

bool Check(const string &num, const string &floor)
{
    for(int i = 0; i < num.size(); i++)
    {
        if(num[i] != floor[i])
        {
            if(num[i] == '.' && floor[i] == '#') return false;
        }
    }
    return true;
}

vector<int> FindPossibleNum(const vector<string> &nums, const string &floor)
{
    vector<int> possible;
    int idx = 0;
    for(const auto &num : nums)
    {
        if(Check(num, floor)) possible.push_back(idx);
        idx++;
    }
    return possible;
}


int main()
{
    cin >> N;
    vector<string> floors;
    vector<string> nums; // 0~9
    vector<vector<int>> v; // 가능한 숫자들
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4*N-1; j++)
        {
            cin >> A[i][j];
        }
    }

    SepNums(floors);
    SaveNums(nums);

    for(const auto &floor : floors)
    {
        vector<int> possible = FindPossibleNum(nums, floor);
        if(!possible.empty()) v.push_back(possible);
        else
        {
            // 가능한 층 수 없음
            cout << -1; return 0;
        }
    }

    double answer = 0;
    for(int i = 0; i < v.size(); i++)
    {
        double sum = 0;
        for(int j = 0; j < v[i].size(); j++)
        {
            sum += v[i][j];
        }
        sum /= (double)v[i].size();
        sum *= pow(10, (int)v.size()-1-i);
        answer += sum;
    }

    cout.precision(5);
    cout << fixed << answer;

}