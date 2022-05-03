#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



class Node
{
public:
    Node *prev;
    Node *next;
    int data;

    Node(int _data)
    {
        prev = nullptr;
        next = nullptr;
        data = _data;
    }
};

vector<Node*> removed;
class DLinkedList
{
public:
    Node *head;
    Node *tail;

    DLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void Insert(int data)
    {
        Node *newNode = new Node(data);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    // it이 가르키는 노드 지우고, 조건에 맞는 노드 리턴
    Node* Erase(Node *it)
    {
        Node *ret = it;

        // head 노드를 지울때
        if(it == head)
        {
            ret = it->next;
            head = it->next;
            it->next->prev = nullptr;
        }
        else if(it == tail) // tail 노드를 지울때
        {
            ret = it->prev;
            tail = it->prev;
            it->prev->next = nullptr;
        }
        else
        {
            ret = it->next;
            it->prev->next = it->next;
            it->next->prev = it->prev;
        }
        // 지운 노드 정보 저장
        removed.push_back(it);
        return ret;
    }
    void Restore()
    {
        Node *reNode = removed.back();
        removed.pop_back();

        if(reNode->prev == nullptr) // 복구 노드가 head
        {
            head = reNode;
            reNode->next->prev = reNode;
        }
        else if(reNode->next == nullptr) // 복구 노드가 tail
        {
            tail = reNode;
            reNode->prev->next = reNode;
        }
        else
        {
            reNode->prev->next = reNode;
            reNode->next->prev = reNode;
        }
    }
};

string solution(int n, int k, vector<string> cmd)
{
    // 양방향 연결리스트 생성
    DLinkedList *list = new DLinkedList();
    for(int i = 0; i < n; i++) list->Insert(i);

    // iterator
    Node *it = list->head;
    for(int i = 0; i < k; i++) it = it->next;

    for(const auto &op : cmd)
    {
//        cout << op[0] << endl;
//        cout << "it: " << it->data << endl;
//        Node *it2 = list->head;
//        while(it2 != nullptr)
//        {
//            cout << it2->data << ' ';
//            it2 = it2->next;
//        } cout << endl << endl;

        if(op[0] == 'U')
        {
            int x = stoi(op.substr(2));
            for(int i = 0; i < x; i++) it = it->prev;
        }
        else if(op[0] == 'D')
        {
            int x = stoi(op.substr(2));
            for(int i = 0; i < x; i++) it = it->next;
        }
        else if(op[0] == 'C')
        {
            it = list->Erase(it);
        }
        else if(op[0] == 'Z')
        {
            list->Restore();
        }
    }


    vector<bool> mark(n, false);
    it = list->head;
    while(it != nullptr)
    {
        mark[it->data] = true;
        it = it->next;
    }

    string answer;
    for(int i = 0; i < n; i++)
    {
        if(mark[i]) answer.push_back('O');
        else answer.push_back('X');
    }

    return answer;
}

int main()
{
    vector<string> cmd =
            {
                    "D 2","C","U 3","C","D 4","C","U 2","Z","Z"
            };
    solution(8, 2, cmd);
}