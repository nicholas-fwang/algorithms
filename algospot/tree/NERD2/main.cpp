#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int N;
map<int, int> nerd;

bool isDominated(int x, int y)
{
  auto it = nerd.lower_bound(x);
  if(it == nerd.end()) return false;

  return y < it->second;
}

void removeDominated(int x, int y)
{
  auto it = nerd.lower_bound(x);
  if(it == nerd.begin()) return ;
  --it;

  while(true) {
    if(it->second > y) break;
    if(it == nerd.begin()) {
      nerd.erase(it);
      break;
    } else {
      auto jt = it;
      --jt;
      nerd.erase(it);
      it = jt;
    }
  }
}

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    nerd.clear();
    scanf("%d", &N);
    int ret = 0;
    for(int i=0; i<N; i++) {
      int x,y;
      scanf("%d %d", &x, &y);
      if(!isDominated(x,y)) {
        removeDominated(x,y);
        nerd[x] = y;
      }
      printf("%d\n", nerd.size());
      ret += nerd.size();
    }
    printf("%d\n", ret);
  }
  return 0;
}
