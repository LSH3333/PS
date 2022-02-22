#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 99999999;
    int weakSize = weak.size();
    int distSize = dist.size();
    for(int i = 0; i < weakSize; i++) weak.push_back(weak[i] + n);
    sort(dist.begin(), dist.end());

    // weak 벡터
    for(int w = 0; w < weakSize; w++)
    {
//        cout << "weak: ";
//        for(auto x : weak) cout << x << ' '; cout << endl;
//        cout << "w: " << w << endl;

        // dist 벡터 셔플
        do {
//            for(auto x : dist) cout << x << ' '; cout << endl;

            int distIdx = 0;
            int curIdx = w;
            int curVal = weak[curIdx];
            bool trigger = false;
            while(distIdx < distSize)
            {
                curVal = curVal + dist[distIdx++];
                curIdx = upper_bound(weak.begin(), weak.end(), curVal) - weak.begin();
                curVal = weak[curIdx];
                if(curIdx - w >= weakSize) { trigger = true; break; }
            }
            if(trigger) answer = min(answer, distIdx);

//            cout << distIdx << endl;
        } while(next_permutation(dist.begin(), dist.end()));
//        cout << endl;
    }

//    cout << endl << "answer: " << answer;
    if(answer == 99999999) answer = -1;
    return answer;
}

int main()
{
//    vector<int> weak = {1, 5, 6, 10};
//    vector<int> dist = {1, 2, 3, 4};
//    solution(12, weak, dist);


    vector<int> weak = {1, 3, 4, 9, 10};
    vector<int> dist = {3, 5, 7};
    solution(12, weak, dist);
}