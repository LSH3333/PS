#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    vector<vector<int>> arr(n, vector<int>(n));
    arr[0][0] = 1;
    for(int idx = 1; idx < n; idx++)
    {
        int r = idx;
        int c = 0;

        // to right
        while(true)
        {
            arr[r][c] = idx+1;
            if(c >= idx) break;
            c++;
        }
        // to up
        while(true)
        {
            arr[r][c] = idx+1;
            if(r == 0) break;
            r--;
        }
    }

    long long left_r = left / n;
    long long left_c = left % n;
    long long right_r = right / n;
    long long right_c = right % n;

    for(long long i = left_c; i < n; i++) answer.push_back(arr[left_r][i]);
    for(long long i = left_r+1; i < right_r; i++)
    {
        for(int j = 0; j < n; j++) answer.push_back(arr[i][j]);
    }
    for(long long i = 0; i <= right_c; i++) answer.push_back(arr[right_r][i]);

    return answer;
}

int main()
{
    solution(3,2,5);
//    solution(4,7,14);
}