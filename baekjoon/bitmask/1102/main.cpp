// FAIL

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int oo = 0x3f3f3f3f;

int N;
int cache[1<<17];
int cost[16][16];
int P;

int bitCount(int state) {
  if(state == 0) return 0;
  return state%2 + bitCount(state/2);
}

int solve(int state)
{
  // 갯수가 P 이상이면 비용 리턴
  if(bitCount(state) >= P) {
    return 0;
  }
  // memoization
  int& ret = cache[state];
  if(ret != -1) {
    return ret;
  }
  ret = oo;

  // Yes를 돌면서 Yes가 하나씩 킨다.
  for(int i=0; i<N; i++) {
    if((state & (1<<i))) {
      for(int j=0; j<N; j++) {
        if((state & (1<<j))) continue;
        ret = min(ret, solve(state|(1<<j)) + cost[i][j]);
      }
    }
  }
  return ret;
}

int main()
{
  memset(cache, -1, sizeof(cache));
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      scanf("%d", &cost[i][j]);
    }
  }
  string s;
  cin >> s;
  int state = 0;
  for(int i=0; i<s.size(); i++) {
    if(s[i] == 'Y') {
      state |= (1<<i);
    }
  }
  scanf("%d", &P);
  int ret = solve(state);
  if(ret == oo) ret = -1;
  else printf("%d\n", ret);
  return 0;
}
