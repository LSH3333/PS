#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    int n = dungeons.size();
    int d[10];
    for(int i = 1; i <= n; i++) d[i] = i;


    do {
        int energy = k, cnt = 0;

        for(int i = 1; i <= n; i++)
        {
            int idx = d[i];
            if(energy < dungeons[idx-1][0]) break;
            energy -= dungeons[idx-1][1];
            cnt++;
        }

        answer = max(answer, cnt);
    } while(next_permutation(d+1, d+n+1));


    return answer;
}
