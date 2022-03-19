#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int N, K, L;
int arr[110][110];
deque<pair<int, char>> turn;
deque<pair<int,int>> snake;

bool MoveSnake(int dir)
{
    // head
    int nr = snake.front().first + dr[dir];
    int nc = snake.front().second + dc[dir];
    // head가 현재 방향으로 움직이면 맵 범위 벗어남
    if(nr < 1 || nr > N || nc < 1 || nc > N) return false;
    // head가 현재 방향으로 움직이면 자기 자신과 부딪힘
    if(arr[nr][nc] == 2) return false;

    // head가 현재 방향으로 움직이면 사과가 있음
    if(arr[nr][nc] == 1)
    {
        snake.push_front({nr, nc});
        arr[nr][nc] = 2;
        return true;
    }

    // 사과없음
    // 끝 부분은 0으로
    arr[snake.back().first][snake.back().second] = 0;
    for(int i = snake.size()-1; i >= 0; i--)
    {
        if(i == 0)
        {
            snake[i].first = nr;
            snake[i].second = nc;
            arr[nr][nc] = 2;
        }
        else
        {
            snake[i].first = snake[i-1].first;
            snake[i].second = snake[i-1].second;
            // 새롭게 이동한 자리는 2로 채움
            arr[snake[i].first][snake[i].second] = 2;
        }
    }

    return true;
}

int main()
{
    // input
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int a, b; cin >> a >> b;
        arr[a][b] = 1;
    }
    cin >> L;
    for(int i = 0; i < L; i++)
    {
        int a; char b;
        cin >> a >> b;
        turn.push_back({a, b});
    }

    // 뱀 최초위치, 방향
    snake.push_back({1,1});
    arr[1][1] = 2;
    int dir = 1, sec = 0;
    while(true)
    {
        sec++;
        // move
        if(!MoveSnake(dir)) break;

        // turn
        if(!turn.empty() && sec == turn.front().first)
        {
            if(turn.front().second == 'D') dir = (dir + 1) % 4;
            else
            {
                dir = dir - 1;
                if(dir < 0) dir = 3;
            }

            turn.pop_front();
        }
    }

    cout << sec;
}œ