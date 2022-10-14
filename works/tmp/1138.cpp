#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> order(N+1, 0);
    for(int i = 1; i <= N; i++) cin >> order[i];

    vector<int> line; line.push_back(0);
    for(int i = 1; i <= N; i++) line.push_back(i);

    do
    {
        bool isAnswer = true;
        for(int i = 1; i <= N; i++)
        {
            int cur = line[i];
            int taller = order[cur];
            int cnt = 0;
            for(int j = 1; j < i; j++)
            {
                if(line[j] > line[i]) cnt++;
            }
            if(cnt != taller) { isAnswer = false; break; }
        }

        if(isAnswer)
        {
            for(int i = 1; i <= N; i++) cout << line[i] << ' ';
            break;
        }
    } while(next_permutation(line.begin()+1, line.end()));

}