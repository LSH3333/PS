#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 이분탐색?
// 
int solution(vector<int> a) {
    int answer = 0;
//    for(auto x : a) cout << x << ' '; cout << endl;

    int minLeft = a[0];
    int minRight = *min_element(a.begin()+2, a.end());

    for(int i = 1; i < a.size()-1; i++)
    {
        if(a[i] == minRight)
        {
            minRight = *min_element(a.begin()+i+1, a.end());
        }
        if(a[i-1] < minLeft)
        {
            minLeft = a[i-1];
        }

        // a[i]가 minLeft보다도 크고 and minRight보다도 크면 불가능
        if(!(a[i] > minLeft && a[i] > minRight)) answer++;
    }

//    cout << answer+2;
    return answer+2;
}