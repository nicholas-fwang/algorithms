#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;

vector<int> slice(const vector<int>& order, int start, int end)
{
  return vector<int>(order.begin()+start, order.begin()+end);
}

void printPostorder(const vector<int>& preorder, const vector<int>& inorder)
{
  int N = preorder.size();

  if(preorder.empty()) return ;

  int root = preorder[0];

  int left;
  for(int i=0; i<N; i++) {
    if(root == inorder[i]) {
      left = i;
      break;
    }
  }
  int right = N-1-left;

  printPostorder(slice(preorder, 1, left+1), slice(inorder, 0, left));
  printPostorder(slice(preorder, left+1, N), slice(inorder, left+1, N));

  printf("%d ", root);
}

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    scanf("%d", &N);
    vector<int> preorder(N);
    vector<int> inorder(N);
    for(int i=0; i<N; i++) {
      scanf("%d", &preorder[i]);
    }
    for(int i=0; i<N; i++) {
      scanf("%d", &inorder[i]);
    }
    printPostorder(preorder, inorder);
  }
  return 0;
}
