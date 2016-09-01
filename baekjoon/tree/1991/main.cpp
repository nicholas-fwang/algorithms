#include <cstdio>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    char value;  
    Node* left;
    Node* right;
};

// 찾아야하는 노드의 value인 parent를 root를 이용해 찾은 후 왼쪽에 새롭게 노드를 생성해 value를 넣는다.
void findAndattachToLeft(Node* root, char parent, char value);
// 찾아야하는 노드의 value인 parent를 root를 이용해 찾은 후 오른쪽에 새롭게 노드를 생성해 value를 넣는다.
void findAndattachToRight(Node* root, char parent, char value);

void printPreorder(Node* root);
void printInorder(Node* root);
void printPostorder(Node* root);
int main()
{
    int n;
    scanf("%d", &n);
    char parent, left, right;
    // root 노드를 만들고 추가한다
    Node* root;
    cin >> parent >> left >> right;
    root = (Node *)malloc(sizeof(Node));
    root->value = parent;
    root->left = NULL;
    root->right = NULL;
    findAndattachToLeft(root, parent, left);
    findAndattachToRight(root, parent, right);
    for(int i=0; i<n-1; i++) {
        cin >> parent >> left >> right;
        findAndattachToLeft(root, parent, left);
        findAndattachToRight(root, parent, right);
    }
    
    // 트리 순회 탐색
    printPreorder(root); printf("\n");
    printInorder(root); printf("\n");
    printPostorder(root); printf("\n");
    return 0;
}

void findAndattachToLeft(Node* root, char parent, char value)
{
    if(root == NULL) {
        return ;
    }
    
    // '.'은 노드가 없는다는 것을 의미한다
    if(value == '.') {
        return ;
    }
    
    if(root->value == parent) {
        Node* newNode;
        newNode = (Node*) malloc(sizeof(Node));
        root->left = newNode;
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return ;
    }
    
    // parent 노드가 발견될때까지 탐색
    findAndattachToLeft(root->left, parent, value);
    findAndattachToLeft(root->right, parent, value);
}
void findAndattachToRight(Node* root, char parent, char value)
{
    if(root == NULL) {
        return ;
    }
    
    // '.'은 노드가 없는다는 것을 의미한다
    if(value == '.') {
        return ;
    }
    
    if(root->value == parent) {
        Node* newNode;
        newNode = (Node*) malloc(sizeof(Node));
        root->right = newNode;
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;  
        return ;
    }
    
    // parent 노드가 발견될때까지 탐색
    findAndattachToRight(root->left, parent, value);
    findAndattachToRight(root->right, parent, value);
}

void printPreorder(Node* root)
{
    printf("%c", root->value);
    if(root->left != NULL) printPreorder(root->left);
    if(root->right != NULL) printPreorder(root->right);
}
void printInorder(Node* root)
{
    if(root->left != NULL) printInorder(root->left);
    printf("%c", root->value);
    if(root->right != NULL) printInorder(root->right);
}
void printPostorder(Node* root)
{
    if(root->left != NULL) printPostorder(root->left);
    if(root->right != NULL) printPostorder(root->right);
    printf("%c", root->value);
}