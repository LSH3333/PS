#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

#define MAX 1000000

struct Node {
    Node *prev;
    Node *next;
    int data;
    Node(Node *prev, Node *next, int data) {
        this->prev = prev;
        this->next = next;
        this->data = data;
    }
};


string solution(int n, int k, vector<string> cmd) {
    // removed Node stack
    stack<Node*> removed;
    // doubly linked list
    Node *tmp = new Node(nullptr, nullptr, 0);
    Node *it = tmp;
    for(int i = 1; i < n; i++) {
        tmp->next = new Node(tmp, nullptr, i);
        tmp = tmp->next;
    }
    // k ?? ?
    for(int i = 0; i < k; i++) {
        it = it->next;
    }

    for(const auto &op : cmd) {
//        cout << op << endl;

        if (op.front() == 'U') {
            for(int i = 0; i < stoi(op.substr(2)); i++) {
                it = it->prev;
            }
        }
        else if (op.front() == 'D') {
            for(int i = 0; i < stoi(op.substr(2)); i++) {
                it = it->next;
            }
        }
        else if (op.front() == 'C') {
            removed.push(it);

            if (it->prev == nullptr) {
                it->next->prev = nullptr;
                it = it->next;
            }
            else if (it->next == nullptr) {
                it->prev->next = nullptr;
                it = it->prev;
            }
            else {
                it->prev->next = it->next;
                it->next->prev = it->prev;
                it = it->next;
            }
        }
        else { // 'Z'
            if (removed.top()->prev == nullptr) {
                removed.top()->next->prev = removed.top();
            }
            else if (removed.top()->next == nullptr) {
                removed.top()->prev->next = removed.top();
            }
            else {
                removed.top()->next->prev = removed.top();
                removed.top()->prev->next = removed.top();
            }
            removed.pop();
        }
    }

    string answer(n, 'O');
    while (!removed.empty()) {
        answer[removed.top()->data] = 'X';
        removed.pop();
    }

    return answer;
}

int main() {
    int n = 8;
    int k = 2;
    vector<string> cmd = {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"};
//    int n = 8;
//    int k = 2;
//    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
    const string &basicString = solution(n, k, cmd);

    cout << basicString;
}