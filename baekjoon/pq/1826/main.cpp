#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, less<int> > maxHeap;
pair<int, int> arr[10001];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d %d", &arr[i].first, &arr[i].second);
  }
  sort(arr, arr+n);
  int l, p;
  scanf("%d %d", &l, &p);
  int ret = 0;
  int idx=0;
  while(p < l) {
    while(arr[idx].first <= p) {
      if(idx == n) break;
      maxHeap.push(arr[idx].second);
      idx++;
    }
    if(maxHeap.empty()) break;
    p += maxHeap.top();
    maxHeap.pop();
    ret++;
  }
  if(p < l) printf("-1\n");
  else printf("%d\n", ret);
  return 0;
}
