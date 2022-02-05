#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int mark[51][51];
int N;

vector<vector<int>> Rotate(vector<vector<int>> board)
{
    vector<vector<int>> new_board(board.begin(), board.end());

    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            new_board[i][j] = board[j][board.size()-1-i];
        }
    }
    return new_board;
}

vector<pair<int,int>> bfs(int _r, int _c, vector<vector<int>> &table)
{
    vector<pair<int,int>> shape;
    queue<pair<int,int>> q;
    mark[_r][_c] = true;
    q.push({_r,_c});

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        shape.push_back({r,c});
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(mark[nr][nc] || table[nr][nc] == 0) continue;
            q.push({nr,nc});
            mark[nr][nc] = true;
        }
    }
    return shape;
}

void dfs(vector<pair<int,int>> shape, vector<vector<bool>> &dfs_mark)
{

    for(int i = 0; i < 4; i++)
    {
        // shape 통체로 칸 이동
        for(auto x : shape)
        {
            int nr = x.first + dr[i];
            int nc = x.second + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

        }
    }
}

void ToZeroPoint(vector<pair<int,int>> &shape)
{
    // 원점까지 거리
    int _r = shape[0].first;
    int _c = shape[0].second;

    for(auto &x : shape)
    {
        x.first -= _r;
        x.second -= _c;
    }

    // 보드판 벗어났을경우
    while(true)
    {
        bool trigger = false;
        for(auto x : shape)
        {
            // 위로 벗어났을 경우
            if(x.first < 0)
            {
                trigger = true;
                // 아래로 한칸씩
                for(auto &y : shape)
                {
                    y.first += dr[2];
                    y.second += dc[2];
                }
            }
                // 좌측으로 벗어났을 경우
            else if(x.second < 0)
            {
                trigger = true;
                // 우측으로 한칸씩
                for(auto &y : shape)
                {
                    y.first += dr[1];
                    y.second += dc[1];
                }
            }
        }
        // 더이상 보드판 벗어난 블록없음
        if(!trigger) break;
    }
}

// 블록 맞을 경우 game_board는 해당 블록 위치가 채워짐
bool checkFit(vector<pair<int,int>> shape, vector<vector<int>> &game_board)
{
    // 자리 빈칸인지 확인
    for(auto x : shape)
    {
        if(game_board[x.first][x.second] == 1) return false;
    }

    // 인접블록 확인
    for(auto x : shape) game_board[x.first][x.second] = 1;
    for(auto x : shape)
    {
        for(int i = 0; i < 4; i++)
        {
            int nr = x.first + dr[i];
            int nc = x.second + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            // 인접블록이 비었음, 불가
            if(game_board[nr][nc] == 0)
            {
                // 블록 채워놓은 부분 되돌리고 return false
                for(auto y : shape) game_board[y.first][y.second] = 0;
                return false;
            }
        }
    }

    return true;
}

void PrintBoard(vector<vector<int>> &game_board)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << game_board[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    N = table.size();
    // 모형들 좌측상단에 있을때 좌표
    vector<vector<pair<int,int>>> shapes;

    // 각 shape들 좌표 저장
    for(int i = 0; i < table.size(); i++)
    {
        for(int j = 0; j < table.size(); j++)
        {
            if(table[i][j] == 1 && !mark[i][j])
            {
                vector<pair<int,int>> shape = bfs(i, j, table);
                ToZeroPoint(shape);
                shapes.push_back(shape);
            }
        }
    }

    vector<bool> shapeMark(shapes.size(), false);
    for(int rot = 0; rot < 4; rot++)
    {
//        PrintBoard(game_board);
        int idx = -1;
        for(auto shape : shapes)
        {
//            cout << "-----idx: " << idx << endl;
            idx++;
            // 이미 사용한 모형
            if(shapeMark[idx]) continue;

            // 1:right, 3:left
            int leftRight = 1;
            while(true)
            {
                // 블록 맞으면 블록크기 만큼 갯수 증가
                if(checkFit(shape, game_board))
                {
                    answer += shape.size();
//                    cout << "cnt: " << answer << endl;
                    // 해당 모형 사용처리
//                    cout << "idx: " << idx << endl;
                    shapeMark[idx] = true;
                    break;
                }

                // 가로세로 이동
                bool possible = false;
                for(auto x : shape)
                {
                    int nr = x.first + dr[leftRight];
                    int nc = x.second + dc[leftRight];
                    if(nr < 0 || nr >= N || nc < 0 || nc >= N) { possible = false; break; }
                    else possible = true;
                }
                // 가능하다면 모형 옮김
                if(possible)
                {
                    for(auto &x : shape)
                    {
                        x.first += dr[leftRight];
                        x.second += dc[leftRight];
                    }
                }
                    // 가로세로 이동 불가능하다면 아래로
                else
                {
                    bool downPossible = false;
                    for(auto x : shape)
                    {
                        int nr = x.first + dr[2];
                        int nc = x.second + dc[2];
                        if(nr < 0 || nr >= N || nc < 0 || nc >= N) {downPossible = false; break; }
                        else downPossible = true;
                    }
                    if(downPossible)
                    {
                        for(auto &x : shape)
                        {
                            x.first += dr[2];
                            x.second += dc[2];
                        }
                        leftRight = leftRight == 1 ? 3 : 1;
                    }
                    else // 아래로 더이상 못간다면 끝
                        break;
                }
            }
        }
        game_board = Rotate(game_board);
    }

//    PrintBoard(game_board);

//    cout << "answer: " << answer << endl;
    return answer;
}

int main()
{
    vector<vector<int>> game_board =
            {
                    {1,1,0,0,1,0},
                    {0,0,1,0,1,0},
                    {0,1,1,0,0,1},
                    {1,1,0,1,1,1},
                    {1,0,0,0,1,0},
                    {0,1,1,1,0,0}
            };
    vector<vector<int>> table =
            {
                    {1,0,0,1,1,0},
                    {1,0,1,0,1,0},
                    {0,1,1,0,1,1},
                    {0,0,1,0,0,0},
                    {1,1,0,1,1,0},
                    {0,1,0,0,0,0}
            };
    solution(game_board, table);
}