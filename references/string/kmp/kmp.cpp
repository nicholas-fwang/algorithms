#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getpi(string N)
{
  int n = N.size();
  vector<int> pi(n, 0);
  int j=0;
  for(int i=1; i<n; i++) {
    while(j > 0 && N[i] != N[j]) {
      j = pi[j-1];
    }
    if(N[i] == N[j]) {
      pi[i] = ++j;
    }
  }
}

vector<int> kmpSearch(string H, string N)
{
  int h = H.size();
  int n = N.size();

  vector<int> ret;

  int j=0;
  for(int i=0; i<h; i++) {
    while(j > 0 && H[i] != N[j]) {
      j = pi[j-1];
    }
    if(H[i] == N[j]) {
      j++;
      if(j == n) {
        ret.push_back(i-n+1);
        j = pi[j-1];
      }
    }
  }
}
