#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int N, K;
int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    scanf("%d %d", &K, &N);
    long long a = 1983;
    int result = 0;
    int sum = 0;
    queue<int> range;
    for(int i=0; i<N; i++) {
      if(i > 0) {
        a = (a*214013 + 2531011) % (1L<<32);
      }
      int signal = a % 10000 + 1;
      sum += signal;
      range.push(signal);
      while(sum > K) {
        sum -= range.front();
        range.pop();
      }
      if(sum == K) result++;
    }
    printf("%d\n", result);
  }
  return 0;
}
