#include <iostream>
#define MAX 100000
using namespace std;

int size = 0;
int q[MAX];

// 첫 요소, 즉 최대 우선순위 값 리턴, 여기선 max heap이므로 가장 큰 값
int peek(int arr[])
{
    // 편의를 위해 인덱스는 0이 아닌 1부터 시작
    return arr[1];
}

// 노드 삽입
void enqueue(int arr[], int val)
{
    int i = 0;
    if(size == MAX) cout << "OVERFLOW" << endl;

    // heap의 마지막에 노드 삽입
    size++;
    i = size;
    arr[i] = val;

    // 삽입한 노드를 부모노드와 비교해 heap 속성에 위배될 경우 자리 바꿈 (루트에 도달할때까지 반복)
    while(i > 1 && arr[i/2] < arr[i])
    {
        swap(arr[i/2], arr[i]);
        i = i / 2;
    }
}


// 트리에 max heap 속성을 유지시키는 작업
void max_heapify(int arr[], int i)
{
    // 현재 노드와 자식 노드를 비교해서 더 큰 값을 갖는 자식과 교환한다
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // 현재 노드 i와 자식 노드 크기 비교 (왼쪽 자식과 오른쪽 자식 중 누가 더 큰지)
    if(left <= size && arr[left] > arr[i]) largest = left;
    if(right <= size && arr[right] > arr[largest]) largest = right;

    // 현재 노드보다 자식 노드에 더 큰 값이 있다면 교환하고,
    // 자식 노드 부터 heapify 진행
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest);
    }
}

// 큐의 첫 요소 추출
int dequeue(int arr[])
{
    if(size == 0) { cout << "Queue Empty" << endl; return 0; }

    // 루트 노드의 값을 추출하고
    int max = arr[1];
    // heap의 마지막 노드를 루트에 배치한다
    arr[1] = arr[size];
    size--;

    // 루트 노드부터 heapify 실행한다
    max_heapify(arr, 1);

    return max;
}

int main()
{
    enqueue(q, 100);
    enqueue(q, 10);
    enqueue(q, 200);
    enqueue(q, 300);

    while(size > 0)
    {
        cout << dequeue(q) << endl;
    }
}