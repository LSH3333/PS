#include <iostream>
#include <vector>
using namespace std;

#define START 0
#define END 1
#define RED 2
#define BLUE 3

struct Node
{
    int idx;
    int status; // 0: start, 1: end, 2: red, 3:blue
    int score;
    bool isPiece; // 해당 노드 말 존재 여부
    vector<Node*> next; // 파랑 화살표는 무조건 가장 마지막 요소
};

void MakeNodes(vector<Node> &nodes)
{
    int idx = 0;
    // begin ~ 2 ~ 40 ~ end
    for(int score = 0; score <= 42; score+=2)
    {
        Node node;
        if(score == 0) // start
        {
            node.score = 0;
            node.status = START;
            node.next.push_back(&nodes[idx+1]);
        }
        else if(score == 42) // end (idx=21)
        {
            node.score = 0;
            node.status = END;
        }
        else if(score == 10 || score == 20 || score == 30) // blue
        {
            node.score = score;
            node.status = BLUE;
            node.next.push_back(&nodes[idx+1]);
        }
        else // red
        {
            node.score = score;
            node.status = RED;
            node.next.push_back(&nodes[idx+1]);
        }
        node.idx = idx;
        nodes[idx++] = node;
    }

    // 10에서 오른쪽으로 19까지
    nodes[5].next.push_back(&nodes[idx]);
    for(int score = 13; score <= 19; score += 3)
    {
        Node node;
        node.idx = idx;
        node.score = score;
        node.status = RED;
        node.next.push_back(&nodes[idx+1]);
        nodes[idx++] = node;
    }
    // 가운데 25 (idx도 25)
    nodes[idx].idx = 25;
    nodes[idx].score = 25;
    nodes[idx].status = RED;

    // 20->22
    nodes[10].next.push_back(&nodes[26]);

    // 22
    idx = 26;
    nodes[idx].idx = idx;
    nodes[idx].score = 22;
    nodes[idx].status = RED;
    nodes[idx].next.push_back(&nodes[idx+1]);

    // 24
    idx = 27;
    nodes[idx].idx = idx;
    nodes[idx].score = 24;
    nodes[idx].status = RED;
    nodes[idx].next.push_back(&nodes[25]);

    // 24 -> 25
    nodes[27].next.push_back(&nodes[25]);

    // 28 ~ 26
    idx = 28;
    for(int score = 28; score >= 26; score--)
    {
        Node node;
        node.idx = idx;
        node.score = score;
        node.status = RED;
        if(score == 26) node.next.push_back(&nodes[25]);
        else node.next.push_back(&nodes[idx+1]);
        nodes[idx++] = node;
    }

    // 오른쪽 30 -> 28
    nodes[15].next.push_back(&nodes[28]);

    // 30 (idx=31)
    nodes[idx].idx = idx;
    nodes[idx].score = 30;
    nodes[idx].status = RED;
    nodes[idx].next.push_back(&nodes[idx+1]);

    // 35 (idx=32)
    idx = 32;
    nodes[idx].idx = idx;
    nodes[idx].score = 35;
    nodes[idx].status = RED;
    nodes[idx].next.push_back(&nodes[20]);

    // 25 -> 30
    nodes[25].next.push_back(&nodes[31]);
}

struct Piece
{
    int idx; // 말 위치
    bool isGoal; // 골 여부
};

int dice[10];
Piece piece[4];
int answer;

// 빨강 노드에서 출발, cnt 만큼 가봄
// 도착 노드에 말 이미 있으면 -1 리턴
// 골 도착시 -2 리턴
// 없으면 도착 노드 인덱스 번호 리턴
int RTryGo(int pIdx, int cnt, vector<Node> &nodes)
{
    // 현재 말이 있는 노드 인덱스
    int curIdx = piece[pIdx].idx;

    for(int i = 0; i < cnt; i++)
    {
         curIdx = nodes[curIdx].next.front()->idx;
        if(curIdx == 21) return -2;
    }

    if(nodes[curIdx].status != END && nodes[curIdx].isPiece) return -1;
    return curIdx;
}

// 파랑 노드에서 출발
int BTryGo(int pIdx, int cnt, vector<Node> &nodes)
{
    int curIdx = piece[pIdx].idx;
    for(int i = 0; i < cnt; i++)
    {
        curIdx = nodes[curIdx].next.back()->idx;
        if(curIdx == 21) return -2;
    }
    if(nodes[curIdx].status != END && nodes[curIdx].isPiece) return -1;
    return curIdx;
}

void dfs(int dIdx, int score, vector<Node> &nodes)
{
    if(dIdx == 10)
    {
        answer = max(answer, score);
        return;
    }


    for(int pIdx = 0; pIdx < 4; pIdx++)
    {
        if(piece[pIdx].isGoal) continue;

        int curPIdx = piece[pIdx].idx;
        int cnt = dice[dIdx];

        if(nodes[curPIdx].status == RED || nodes[curPIdx].status == START)
        {
            int res = RTryGo(pIdx, cnt, nodes);
            if(res == -1) continue;
            else if(res == -2) // goal
            {
                nodes[curPIdx].isPiece = false;
                piece[pIdx].isGoal = true;
                piece[pIdx].idx = 21;
                dfs(dIdx+1, score, nodes);
                nodes[curPIdx].isPiece = true;
                piece[pIdx].isGoal = false;
                piece[pIdx].idx = curPIdx;
                continue;
            }
            // go
            nodes[curPIdx].isPiece = false; // 원래 있던 노드
            nodes[res].isPiece = true; // 도착 노드
            piece[pIdx].idx = res;
            dfs(dIdx+1, score+nodes[res].score, nodes);
            nodes[curPIdx].isPiece = true;
            nodes[res].isPiece = false;
            piece[pIdx].idx = curPIdx;
        }
        else if(nodes[curPIdx].status == BLUE)
        {
            int res = BTryGo(pIdx, cnt, nodes);
            if(res == -1) continue;
            else if(res == -2) // goal
            {
                nodes[curPIdx].isPiece = false;
                piece[pIdx].isGoal = true;
                piece[pIdx].idx = 21;
                dfs(dIdx+1, score, nodes);
                nodes[curPIdx].isPiece = true;
                piece[pIdx].isGoal = false;
                piece[pIdx].idx = curPIdx;
                continue;
            }
            nodes[curPIdx].isPiece = false; // 원래 있던 노드
            nodes[res].isPiece = true; // 도착 노드
            piece[pIdx].idx = res;
            dfs(dIdx+1, score+nodes[res].score, nodes);
            nodes[curPIdx].isPiece = true;
            nodes[res].isPiece = false;
            piece[pIdx].idx = curPIdx;
        }
    }
}

int main()
{
    vector<Node> nodes(33);
    MakeNodes(nodes);
    for(int i = 0; i < 32; i++) nodes[i].isPiece = false;

//    for(auto n : nodes)
//    {
//        cout << n.idx << ": " << n.status << ": " << n.score << endl;
//    }


    for(int i = 0; i < 10; i++)
    {
        int s; cin >> s;
        dice[i] = s;
    }

    dfs(0, 0, nodes);
    cout << answer;

}
