#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int> > maxHeap;

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int v;
    scanf("%d", &v);
    if(v == 0) {
      printf("%d\n", maxHeap.empty()? 0 : maxHeap.top());
      if(maxHeap.size() > 0) maxHeap.pop();
    }
    else {
      maxHeap.push(v);
    }
  }
  return 0;
}
