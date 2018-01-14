#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int> > maxHeap;
priority_queue<int, vector<int>, greater<int> > minHeap;

int main()
{
  int n;
  scanf("%d", &n);
  int v;
  scanf("%d", &v);
  maxHeap.push(v);
  printf("%d\n", v);
  for(int i=1; i<n; i++) {
    scanf("%d", &v);
    if(maxHeap.top() < v) minHeap.push(v);
    else maxHeap.push(v);

    if(maxHeap.size() < minHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
    else if(maxHeap.size() > minHeap.size()+1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
    printf("%d\n", maxHeap.top());
  }
  return 0;
}
