#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int N;

// c가 a와 b사이에 포함되는가?
bool Calculate(int a, int b, int c)
{
    int c2 = c + N;
    if(a <= c && c <= b) return true;
    if(a <= c2 && c2 <= b) return true;
    return false;
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size();
    N = n;
    deque<int> de(weak.begin(), weak.end());

    sort(dist.begin(), dist.end());
    do {
//        cout << "dist: ";
//        for(auto x : dist) cout << x << ' '; cout << endl;
        for(int a = 0; a < de.size(); a++)
        {
//            for(auto x : de) cout << x << ' '; cout << endl;
            int distIdx = 0;
            int weakIdx = 0;
            int depart = de[0];
            int arrive = depart + dist[0];
            while(true)
            {
                if(Calculate(depart, arrive, de[weakIdx]))
                {
                    weakIdx++;
                }
                else
                {
                    distIdx++;
                    depart = de[weakIdx];
                    arrive = depart + dist[distIdx];
                }
                if(weakIdx == de.size()) break;
                if(distIdx == dist.size()) { distIdx = -2; break; }
            }

//            cout << distIdx+1 << endl;
            answer = min(distIdx+1, answer);

            int frontN = de.front();
            de.pop_front();
            de.push_back(frontN);
        }
    } while(next_permutation(dist.begin(), dist.end()));
//    cout << "answer: " << answer;
    return answer;
}

int main()
{
    vector<int> weak = {1, 5, 6, 10};
    vector<int> dist = {1, 2, 3, 4};
    solution(12, weak, dist);

    vector<int> weak2 = {1,3,4,9,10};
    vector<int> dist2 = {3,5,7};
    solution(12, weak2, dist2);
}