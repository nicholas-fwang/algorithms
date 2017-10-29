#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string s;

int MAX(int a, int b) {
  return a>b?a:b;
}

vector<int> getpi(string sub)
{
  int n = sub.size();
  vector<int> pi(n,0);

  int j=0;
  for(int i=1; i<n; i++) {
    while(j>0 && sub[i]!=sub[j]) {
      j = pi[j-1];
    }
    if(sub[i] == sub[j]) {
      pi[i] = ++j;
    }
  }
  return pi;
}

int main()
{
  cin >> s;
  int ret = 0;
  for(int i=0; i<s.size(); i++) {
    string sub = s.substr(i);
    vector<int> pi = getpi(sub);
    for(int j=0; j<pi.size(); j++) {
      ret = MAX(ret, pi[j]);
    }
  }

  printf("%d\n", ret);
  return 0;
}
