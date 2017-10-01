#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, K;
int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    scanf("%d %d", &N, &K);
    vector<int> list;
    for(int i=1; i<=N; i++) {
      list.push_back(i);
    }
    vector<int>::iterator kill = list.begin();
    while(list.size() > 2) {
      kill = list.erase(kill);
      if(kill == list.end()) kill = list.begin();
      for(int i=0; i<K-1; i++) {
        kill++;
        if(kill == list.end()) kill = list.begin();
      }
    }
    printf("%d %d\n", list.front(), list.back());
  }
  return 0;
}
