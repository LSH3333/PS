#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int BIdx = 0;
    for(int i = 0; ;)
    {
        // B가 이김
        if(A[i] < B[BIdx])
        {
            answer++;
            i++;
            BIdx++;
        }
        else
        {
            BIdx = upper_bound(B.begin()+BIdx, B.end(), A[i]) - B.begin();
        }

        if(i == A.size() || BIdx == B.size()) break;
    }
    return answer;
}

int main()
{
//    vector<int> A = {1,3,5,7},
//                B = {2,2,6,8};
//    solution(A, B);
    vector<int> A = {2,2,2,2},
            B = {1,1,1,1};
    solution(A, B);
}