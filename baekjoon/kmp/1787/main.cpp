#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int N;
string s;

vector<int> getpi()
{
  int n = s.size();
  vector<int> pi(n,0);
  int matched=0;
  for(int i=1; i<n; i++) {
    while(matched>0 && s[i] != s[matched]) {
      matched = pi[matched-1];
    }
    if(s[i] == s[matched]) {
      pi[i] = ++matched;
    }
  }
  return pi;
}

int main()
{
  scanf("%d", &N);
  cin >> s;
  vector<int> pi = getpi();
  long long ret = 0;
  for(int i=0; i<pi.size(); i++) {
    int p = pi[pi[i]-1];
    if(i>0 && p > 0) {
      pi[i] = p;
    }
    if(pi[i] > 0) ret += (i+1-pi[i]);
  }
  printf("%lld\n", ret);
  return 0;
}
