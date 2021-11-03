#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define MAX 10
using namespace std;

int k;
int nums[MAX];
bool mark[MAX];
char sign[MAX];

// string형태로 저장된 순열들의 집합
vector<string> ans;
// 순열들의 숫자들이 저장됨
vector<char> v;

// 벡터에 들어있는 k개의 숫자들과 부등호의 관계를 비교
// 하나라도 관계가 틀리면 false 리턴
// 모두 옳다면 true 리턴
bool Compare() {
    bool res = true;
    for(int i = 0; i < k; i++) {
        if(sign[i] == '<') {
            // char형을 int형으로 바꿔서 계산
            if(!(v[i]-'0' < v[i+1]-'0')) return false;
        }
        else if(sign[i] == '>') {
            if(!(v[i]-'0' > v[i+1]-'0')) return false;
        }
    }

    return true;
}

void DFS(int depth) {
    if(depth == k+1) {
        // 모든 부등호 관계가 옳다면
        if(Compare()) {
            string temp = "";
            for(int i = 0; i < v.size(); i++) {
                temp += v[i];
            }
            // 만들어진 string을 ans 벡터에 푸쉬
            ans.push_back(temp);
        }
        // 이전 depth로 리턴
        return;
    }


    for(int i = 0; i < 10; i++) {
        if(mark[i]) continue;

        mark[i] = true;
        // +'0'을 함으로서 int형을 char형으로 변환해서 벡터에 저장
        v.push_back(nums[i]+'0');

        DFS(depth+1);

        v.pop_back();
        mark[i] = false;
    }
}

int main() {
    cin >> k;
    // 부등호 sign[]에 저장
    for(int i = 0; i < k; i++)
        cin >> sign[i];

    // 0~9까지의 숫자
    for(int i = 0; i < 10; i++)
        nums[i] = i;

    DFS(0);
    // ans 벡터를 정렬
    sort(ans.begin(), ans.end());

    cout << ans[ans.size()-1] << '\n';
    cout << ans[0] << '\n';

}

