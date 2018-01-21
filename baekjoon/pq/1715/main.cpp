#include <iostream>
#include <cstdio>

using namespace std;

const int oo = 0x3f3f3f3f;

int heap[100001];
int hn;

void push(int x)
{
  heap[++hn] = x;
  for(int i=hn; i>1; i/=2) {
    if(heap[i/2] > heap[i]) {
      swap(heap[i/2], heap[i]);
    }
    else {
      break;
    }
  }
}

int pop()
{
  int ans = heap[1];
  heap[1] = heap[hn];
  heap[hn--] = oo;
  for(int i=1; i*2 <= hn;) {
    if(heap[i] < heap[i*2] && heap[i] < heap[i*2+1]) {
      break;
    }
    else if(heap[i*2] < heap[i*2+1]) {
      swap(heap[i], heap[i*2]);
      i = i*2;
    }
    else {
      swap(heap[i], heap[i*2+1]);
      i = i*2+1;
    }
  }
  return ans;
}

int main()
{
  int n;
  hn = 0;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    push(tmp);
  }

  int ret = 0;
  while(hn > 1) {
    int v1 = pop();
    int v2 = pop();
    push(v1+v2);
    ret += (v1+v2);
  }
  printf("%d\n", ret);
  return 0;
}
