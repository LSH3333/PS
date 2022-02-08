#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N;

string ToBinary(int n)
{
    string s = "";
    while(n > 0)
    {
        s += to_string(n % 2);
        n /= 2;
    }
    while(s.size() < N) s += "0";
    reverse(s.begin(), s.end());
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    N = n;
    vector<string> answer;
    vector<string> map1, map2;
    for(auto x : arr1) map1.push_back(ToBinary(x));
    for(auto x : arr2) map2.push_back(ToBinary(x));

    for(int i = 0; i < map1.size(); i++)
    {
        string str = "";
        for(int j = 0; j < n; j++)
        {
            if(map1[i][j] == '1' || map2[i][j] == '1') str.push_back('#');
            else str.push_back(' ');
        }
        answer.push_back(str);
    }

    return answer;
}
