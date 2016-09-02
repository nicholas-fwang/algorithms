#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

struct Node {
    int number;
    int len;
    vector<Node*> children;
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
        newNode->len = root->len + len;
        root->children.push_back(newNode);
        return ;
    }
    
    for(vector<Node*>::iterator it = root->children.begin(); it != root->children.end(); ++it) {
        findAndAttachChild(*it, parent, child, len);
    }
}

int solve(Node* root)
{
    int ret = 0;
    
    if(root->children.size() >= 1) {
        int max1 = 0, max2 = 0;
        for(int i=0; i<root->children.size(); i++) {
            int tmp = getMax(root->children[i]);
            if(max1 < tmp || max2 < tmp) {
                if(max1 > max2) {
                    max2 = tmp;
                } else {
                    max1 = tmp;
                }
            }
        }
        ret = max1 + max2 - 2*(root->len);
    }
    
    for(vector<Node*>::iterator it = root->children.begin(); it != root->children.end(); ++it) {
        ret = max(ret, solve(*it));
    }
    
    return ret;
}

int getMax(Node* root)
{
    int ret = 0;
    if(root->children.size() == 0) {
        return root->len;
    }
    
    for(vector<Node*>::iterator it = root->children.begin(); it != root->children.end(); ++it) {
        ret = max(ret, getMax(*it));
    }
    
    return ret;
}