#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int ConvertToMin(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
}

struct Task {
    string name;
    int start;
    int playtime;
};

bool cmp(const Task &t1, const Task &t2) {
    return t1.start < t2.start;
}

vector<Task> MakeData(const vector<vector<string>> &plans) {
    vector<Task> tasks;

    for(auto x : plans) {
        string name = x[0];
        int start = ConvertToMin(x[1]);
        int playtime = stoi(x[2]);

        tasks.push_back(Task{name, start, playtime});
    }

    return tasks;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    vector<Task> tasks = MakeData(plans);
    sort(tasks.begin(), tasks.end(), cmp);

    stack<Task> st;
    for(int i = 0; i < tasks.size()-1; i++) {
        st.push(tasks[i]);

        int leftTime = tasks[i+1].start - tasks[i].start;
        while (leftTime > 0 && !st.empty()) {
            // ? ?? ??
            if(st.top().playtime - leftTime <= 0) {
                answer.push_back(st.top().name);
                leftTime -= st.top().playtime;
                st.pop();
            }
            else {
                st.top().playtime -= leftTime;
                break;
            }
        }
    }

    // ??? ??
    st.push(tasks.back());

    while (!st.empty()) {
        answer.push_back(st.top().name);
        st.pop();
    }

    return answer;
}

int main() {
    vector<vector<string>> plans = {
            {"science", "12:40", "50"},
            {"music", "12:20", "40"},
            {"history", "14:00", "30"},
            {"computer", "12:30", "100"}
    };

    solution(plans);
}