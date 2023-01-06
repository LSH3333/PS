#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, answer;
bool found = true;
int goalBegin, goalEnd;
int monthday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool mark[400][400];

int DateToDay(int month, int day) {
    int res = 0;
    for(int i = 1; i < month; i++) res += monthday[i];
    res += day;
    return res;
}

// second 기준 오름차순 정렬, first 기준 오름차순 정렬
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}


int main() {
//    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int,int>> v1(N);
    vector<pair<int,int>> v2(N);
    for(int i = 0; i < N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v1[i] = {DateToDay(a, b), DateToDay(c, d) };
        v2[i] = v1[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), cmp);
    goalBegin = DateToDay(3,1);
    goalEnd = DateToDay(11,30);

    cout << "goal: " << goalBegin << ' ' << goalEnd << endl;
    for(auto x : v1) {
        cout << x.first << ' ' << x.second << endl;
    }cout<<endl;

    for(auto x : v2) {
        cout << x.first << ' ' << x.second << endl;
    }cout<<endl;

    int left = 0, right = N-1;
    while(true) {
        // LEFT
        while(left < N-1) {
            if(left >= N || v1[left].first > goalBegin) {
                left--;
                if(mark[v1[left].first][v1[left].second]) { left++; continue; }
                mark[v1[left].first][v1[left].second] = true;
                break;
            }
            left++;
        }
        goalBegin = v1[left].second;
        answer++;
        cout << "1: " << goalBegin << ' ' << goalEnd << endl;
        if(left >= right && goalBegin <= goalEnd) { found = false; break; }
        if(goalBegin > goalEnd) break;

        // RIGHT
        if(left >= right) {found = false; break;}
        while(right > 0) {
            if(right < 0 || v2[right].second <= goalEnd) {
                right++;
                if(mark[v2[right].first][v2[right].second]) { right--; continue; }
                mark[v2[right].first][v2[right].second] = true;
                break;
            }
            right--;
        }
        goalEnd = v2[right].first-1;
        answer++;
        cout << "2: " << goalBegin << ' ' << goalEnd << endl;
        if(left >= right && goalBegin <= goalEnd) { found = false; break; }
        if(goalBegin > goalEnd) break;
    }

    if(!found) cout << 0;
    else cout << answer;
}