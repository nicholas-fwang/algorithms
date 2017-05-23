#include <stdio.h>

// add, remove, move.. operation 갯수
#define MAXO 100000

struct NODE {
    int id;
    NODE* prev;
    NODE(){};
    NODE(int _id, NODE* _prev) : id(_id), prev(_prev){};
};

NODE heap[MAXO];
int heap_idx = 0;

NODE* head = NULL;

// 넣는 순서대로 출력
void print_node(NODE* _node)
{
    if(_node == NULL) return ;
    print_node(_node->prev);
    printf("%d ", _node->id);
}
int main()
{
    // id 0 추가
    heap[heap_idx] = NODE(0, head);
    head = &heap[heap_idx];
    heap_idx++;
    
    // id 1 추가
    heap[heap_idx] = NODE(1, head);
    head = &heap[heap_idx];
    heap_idx++;
    
    // id 2 추가
    heap[heap_idx] = NODE(2, head);
    head = &heap[heap_idx];
    heap_idx++;
    
    print_node(head);
    return 0;
}