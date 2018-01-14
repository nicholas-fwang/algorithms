#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    priority_queue<ll, vector<ll>, less<ll> > maxHeap;
    priority_queue<ll, vector<ll>, greater<ll> > minHeap;

    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    ll v = 1983;
    maxHeap.push(v);
    long long ret = v;
    for(int i=1; i<n ;i++) {
      v = ((v*a) + b) % 20090711;
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
      ret += maxHeap.top();
    }
    printf("%lld\n", ret%20090711);
  }
  return 0;
}
