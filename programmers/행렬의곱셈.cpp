#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));

    for(int i = 0; i < answer.size(); i++)
    {
        for(int j = 0; j < answer[i].size(); j++)
        {
            int sum = 0;
            for(int a = 0; a < arr1[0].size(); a++)
            {
                sum += arr1[i][a] * arr2[a][j];
            }
            answer[i][j] = sum;
        }
    }

    return answer;
}
