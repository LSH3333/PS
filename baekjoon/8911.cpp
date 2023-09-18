#include <iostream>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Turtle {
    int r;
    int c;
    int dir;
};

void MoveFront(Turtle &turtle) {
    int nr = turtle.r + dr[turtle.dir];
    int nc = turtle.c + dc[turtle.dir];
    turtle.r = nr;
    turtle.c = nc;
}

void MoveBack(Turtle &turtle) {
    int nr = turtle.r + dr[(turtle.dir + 2) % 4];
    int nc = turtle.c + dc[(turtle.dir + 2) % 4];
    turtle.r = nr;
    turtle.c = nc;
}

void TurnL(Turtle &turtle) {
    if(turtle.dir == 0) turtle.dir = 3;
    else turtle.dir = turtle.dir - 1;
}

void TurnR(Turtle &turtle) {
    turtle.dir = (turtle.dir + 1) % 4;
}

void Move(Turtle &turtle, char op) {
    if (op == 'F') {
        MoveFront(turtle);
    }
    else if(op == 'B') {
        MoveBack(turtle);
    }
    else if(op == 'L') {
        TurnL(turtle);
    }
    else {
        TurnR(turtle);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int maxR=0, minR=0, maxC=0, minC=0;
        string ops; cin >> ops;
        Turtle turtle{0, 0, 0};

        for(auto op : ops) {
            Move(turtle, op);

            maxR = max(maxR, turtle.r);
            minR = min(minR, turtle.r);
            maxC = max(maxC, turtle.c);
            minC = min(minC, turtle.c);
        }

        cout << (maxR - minR) * (maxC - minC) << '\n';
    }

}