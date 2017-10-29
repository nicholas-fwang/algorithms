#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string H,N;
vector<int> pi;

void getpi()
{
  int n = N.size();
  pi.resize(n);
  fill(pi.begin(), pi.end(), 0);

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

vector<int> kmpSearch()
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
      if(j == n-1) {
        ret.push_back(i-n+2);
        j = pi[j];
      }
      else {
        j++;
      }
    }
  }
  return ret;
}

int main()
{
  getline(cin, H);
  getline(cin, N);
  getpi();
  vector<int> ret = kmpSearch();
  printf("%d\n", (int)ret.size());
  for(int i=0; i<ret.size(); i++) {
    printf("%d\n", ret[i]);
  }
  return 0;
}
