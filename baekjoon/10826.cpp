#include <iostream>
#include <algorithm>
using namespace std;

string d[10010];

string Add(string A, string B)
{
    string ret;
    if(A.size() > B.size())
    {
        while(A.size() != B.size()) B.push_back('0');
    }
    else
    {
        while(A.size() != B.size()) A.push_back('0');
    }

    int carry = 0;
    for(int i = 0; i < (int)A.size(); i++)
    {
        int a = A[i] - '0';
        int b = B[i] - '0';
        int sum = a + b + carry;
        if(sum > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        char digit = (char)((sum % 10) + '0');
        ret.push_back(digit);
    }
    if(carry == 1)
    {
        return ret + "1";
    }
    else
    {
        return ret;
    }
}

int main()
{
    int N; cin >> N;
    d[0] = "0";
    d[1] = "1";
    for(int i = 2; i <= N; i++)
    {
        d[i] = Add(d[i-1], d[i-2]);
    }

    string answer = d[N];
    reverse(answer.begin(), answer.end());
    cout << answer;
}