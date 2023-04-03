#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string input;
vector<string> answers;

void CheckPairs(vector<pair<int,int>> &pairs) {
    stack<pair<char,int>> st;

    for(int i = 0; i < input.size(); i++) {
        char c = input[i];

        if (c == ')') {
            while (!st.empty() && st.top().first != '(') {
                st.pop();
            }
            pairs.push_back({st.top().second, i});
            if(!st.empty()) st.pop();
        }
        else {
            st.push({c, i});
        }
    }
}

void FindAnswer(const vector<int> &idxs, const vector<pair<int,int>> &pairs) {
    vector<bool> mark(input.size(), false);
    string answer;

    for(auto x : idxs) {
        mark[pairs[x].first] = true;
        mark[pairs[x].second] = true;
    }

    for(int i = 0; i < input.size(); i++) {
        if (input[i] == '(' || input[i] == ')') {
            if(mark[i]) {
                answer.push_back(input[i]);
            }
        }
        else {
            answer.push_back(input[i]);
        }
    }

    answers.push_back(answer);
}

void dfs(int idx, int depth, int goal,
         const vector<pair<int,int>> &pairs,
         vector<bool> &visited,
         vector<int> &idxs) {
    if(depth == goal) {

        FindAnswer(idxs, pairs);

        return;
    }

    for(int i = idx; i < pairs.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        idxs.push_back(i);
        dfs(i, depth + 1, goal, pairs, visited, idxs);
        idxs.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> input;

    vector<pair<int,int>> pairs;
    CheckPairs(pairs);

    for(int i = 0; i < pairs.size(); i++) {
        vector<bool> visited(input.size(), false);
        vector<int> idxs;
        dfs(0, 0, i, pairs, visited, idxs);
    }

    sort(answers.begin(), answers.end());
    answers.erase(unique(answers.begin(), answers.end()), answers.end());
    for(const auto &x : answers) {
        cout << x << '\n';
    }
}