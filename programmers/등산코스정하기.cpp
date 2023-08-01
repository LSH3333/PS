#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 50000
#define GATE 1
#define SUMMIT 2
#define INF 100000000

int N;
int nodes[MAX+1];
vector<pair<int,int>> edges[MAX+1];
int mark[MAX+1];


void MakeData(const vector<vector<int>> &paths, const vector<int> &gates, const vector<int> &summits) {
    for (auto path: paths) {
        int n1 = path[0], n2 = path[1], dist = path[2];
        edges[n1].push_back({n2, dist});
        edges[n2].push_back({n1, dist});
    }

    for(auto gate : gates) {
        nodes[gate] = GATE;
    }

    for (auto summit: summits) {
        nodes[summit] = SUMMIT;
    }
}


void FindIntensity(const vector<int> &gates) {
    // min heap pq
    // intensity, node
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
    for(auto gate : gates) {
        mark[gate] = 0;
        pq.push({0, gate});
    }

    while (!pq.empty()) {
        int cur = pq.top().second;
        int intensity = pq.top().first;
        pq.pop();

        for (auto next: edges[cur]) {
            int nextNode = next.first;
            int dist = next.second;
            int nextIntensity = max(intensity, dist);

            if (mark[nextNode] <= nextIntensity) continue;
            // ?? ??? ?????? ????? ??? ?? ??
            if(nodes[nextNode] == SUMMIT) {
                mark[nextNode] = nextIntensity;
            }
            else {
                mark[nextNode] = nextIntensity;
                pq.push({nextIntensity, nextNode});
            }
        }

    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    N = n;
    vector<int> answer;
    fill(mark, mark+MAX+1, INF);

    MakeData(paths, gates, summits);

    FindIntensity(gates);

    sort(summits.begin(), summits.end());

    int ansIntensity = INF, ansSummit = 0;
    for(auto summit : summits) {
        if(mark[summit] < ansIntensity) {
            ansIntensity = mark[summit];
            ansSummit = summit;
        }
    }

    answer.push_back(ansSummit);
    answer.push_back(ansIntensity);
    return answer;
}

int main() {
//    int n = 6;
//    vector<vector<int>> paths = {
//            {1,2,3}, {2,3,5}, {2,4,2}, {2,5,4}, {3,4,4}, {4,5,3}, {4,6,1}, {5,6,1}
//    };
//    vector<int> gates = {1, 3};
//    vector<int> summits = {5};

//    int n = 5;
//    vector<vector<int>> paths = {
//            {1, 3, 10}, {1, 4, 20}, {2, 3, 4}, {2, 4, 6}, {3, 5, 20}, {4, 5, 6}
//    };
//    vector<int> gates = {1, 2};
//    vector<int> summits = {5, 6};

//    int n = 7;
//    vector<vector<int>> paths = {
//            {1, 2, 5}, {1, 4, 1}, {2, 3, 1}, {2, 6, 7}, {4, 5, 1}, {5, 6, 1}, {6, 7, 1}
//    };
//    vector<int> gates = {3,7};
//    vector<int> summits = {1,5};
//
//    int n = 7;
//    vector<vector<int>> paths = {
//            {1, 3, 10},
//            {1, 4, 20},
//            {2, 3, 4},
//            {2, 4, 6},
//            {3, 5, 20},
//            {4, 5, 6}
//    };
//    vector<int> gates = {1,2};
//    vector<int> summits = {5};

    int n = 7;
    vector<vector<int>> paths = {
            {1,4,4},{1,6,1},{1,7,3},{2,5,2},{3,7,4},{5,6,6}
    };
    vector<int> gates = {2};
    vector<int> summits = {3,4};

    const vector<int> &vector = solution(n, paths, gates, summits);
    cout << endl;
    cout << vector[0] << ' ' << vector[1];
}