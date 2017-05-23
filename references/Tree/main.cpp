#include <stdio.h>

// operation 갯수
#define MAXO 100000
// node 갯수
#define MAXN 10000

struct NODE {
    int id;
    NODE* prev;
    NODE(){};
    NODE(int _id, NODE* _prev) : id(_id), prev(_prev) {};
};

struct TREE_NODE {
    int parent;
    NODE* child;
};

NODE heap[MAXO];
TREE_NODE treeNode[MAXN];

int heap_idx = 0;

void printTree(int id)
{
    printf("child list of ( %d ) ", id);
    for(NODE* _node=treeNode[id].child; _node; _node = _node->prev) {
        printf("%d ", _node->id);
    }
    printf("\n");
    for(NODE* _node=treeNode[id].child; _node; _node = _node->prev) {
        printTree(_node->id);
    }
}

void print_tree(int id)
{
    int rootId = id;
    while(treeNode[rootId].parent != -1) {
        rootId = treeNode[rootId].parent;
    }
    
    printTree(rootId);
}

int main()
{
    for(int i=0; i<MAXN; i++) {
        treeNode[i].parent = -1;
        treeNode[i].child = NULL;
    }
    
    // 0 - 1 추가
    heap[heap_idx] = NODE(1, treeNode[0].child);
    treeNode[0].child = &heap[heap_idx];
    heap_idx++;
    treeNode[1].parent = 0;
    
    // 0 - 2 추가
    heap[heap_idx] = NODE(2, treeNode[0].child);
    treeNode[0].child = &heap[heap_idx];
    heap_idx++;
    treeNode[2].parent = 0;
    
    // 1 - 3 추가
    heap[heap_idx] = NODE(3, treeNode[1].child);
    treeNode[1].child = &heap[heap_idx];
    heap_idx++;
    treeNode[3].parent = 1;
    
    print_tree(3);
    return 0;
}