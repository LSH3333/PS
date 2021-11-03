#include <iostream>
#include <vector>
using namespace std;

int N,M;
int arr[10];
int mark[10];
vector<int> v;

// 벡터 v의 요소들 출력
void Print() {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void DFS(int depth) {
    // M개 출력할것이므로
    // depth이 M+1에 도달하면 벡터 v의 요소 출력하고 이전 depth로 되돌아감
    if(depth == M+1) {
        Print();
        return;
    }

    for(int i = 1; i <= N; i++) {

        // 같은 수를 여러번 골라도 되므로 이 조건은 필요없다.
        //if(mark[i]) continue;
        // 방문 체크
        mark[i] = true;
        // 해당 숫자 벡터에 삽입
        v.push_back(arr[i]);
        // 다음 depth로 이동
        DFS(depth+1);

        // 이 아래 부터는 Print()를 출력한 이후
        // 출력 했으니 마지막 숫자를 pop하고 방문여부를 false로 되돌림
        v.pop_back();
        mark[i] = false;
    }
}

int main() {
    cin >> N >> M;

    // 1부터 N까지의 숫자 배열 생성
    for(int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    // 깊이 1부터 시작
    DFS(1);
}