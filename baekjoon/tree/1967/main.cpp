#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node {
    int number;
    int len;
    Node *left;
    Node *right;
};

void findAndAttachChild(Node* root, int parent, int child, int len);
int solve(Node* root);
int getMax(Node* root);

int main()
{
    int n;
    scanf("%d", &n);
    Node* root;
    root = (Node*)malloc(sizeof(Node));
    root->number = 1;
    root->len = 0;
    root->left = NULL;
    root->right = NULL;
    
    for(int i=0; i<n-1; i++) {
        int parent, child, len;
        scanf("%d %d %d", &parent, &child, &len);
        findAndAttachChild(root, parent, child, len);
    }
    int ret = solve(root);
    printf("%d\n", ret);
    
    return 0;
}

void findAndAttachChild(Node* root, int parent, int child, int len)
{
    if(root == NULL) {
        return ;
    }
    
    if(root->number == parent) {
        Node* newNode;
        newNode = (Node*) malloc(sizeof(Node));
        newNode->number = child;
        newNode->len = len;
        newNode->left = NULL;
        newNode->right = NULL;
        if(root->left == NULL) {
            root->left = newNode;
        } else {
            root->right = newNode;
        }
        return ;
    }
    
    if(root->left) findAndAttachChild(root->left, parent, child, len);
    if(root->right) findAndAttachChild(root->right, parent, child, len);
    
}

int solve(Node* root)
{
    int ret = 0;
    if(root->left && root->right) {
        ret = getMax(root->left) + getMax(root->right);
    }
    
    if(root->left) ret = max(ret, solve(root->left));
    if(root->right) ret = max(ret, solve(root->right));
    return ret;
}

int getMax(Node* root)
{
    if(root == NULL) {
        return 0;
    }
    
    int ret = root->len;
    if(root->left) ret = max(ret, getMax(root->left)+root->len);
    if(root->right) ret = max(ret, getMax(root->right)+root->len);
    
    return ret;
}
