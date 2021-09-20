#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string MakeBinary(int num, int n)
{
    string ret = "";
    while(num > 0)
    {
        int left = num % 2;
        ret += to_string(left);
        num /= 2;
    }

    if(ret.size() != n) ret.append( n-ret.size(), '0');
    reverse(ret.begin(),ret.end());

    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    vector<string> ar1, ar2;
    for(int i = 0; i < n; i++)
    {
        ar1.push_back(MakeBinary(arr1[i],n));
        ar2.push_back(MakeBinary(arr2[i],n));
    }

    for(int i = 0; i < n; i++)
    {
        string row = "";
        for(int j = 0; j < n; j++)
        {
            if(ar1[i][j] == '1' || ar2[i][j] == '1')
            {
                row += "#";
            }
            else if(ar1[i][j] == '0' && ar2[i][j] == '0')
            {
                row += " ";
            }
        }
        answer.push_back(row);
    }

    return answer;
}
