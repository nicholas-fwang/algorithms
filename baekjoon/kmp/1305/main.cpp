#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int L;
string s;

vector<int> getpi()
{
  vector<int> pi(L,0);
  int j=0;
  for(int i=1; i<L; i++) {
    while(j>0 && s[i] != s[j]) {
      j = pi[j-1];
    }
    if(s[i] == s[j]) {
      pi[i] = ++j;
    }
  }
  return pi;
}

int main()
{
  scanf("%d", &L);
  cin >> s;
  vector<int> pi = getpi();
  //왜 L-pi[L-1]가 제일 짧은 광고 길이?
  printf("%d\n", L-pi[L-1]);
}
