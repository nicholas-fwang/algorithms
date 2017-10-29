#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int _N;

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
  return pi;
}

vector<int> kmp(string H, string N)
{
  int h = H.size();
  int n = N.size();

  vector<int> ret;
  vector<int> pi = getpi(N);

  int j=0;
  for(int i=0; i<h; i++) {
    while(j > 0 && N[j] != H[i]) {
      j = pi[j-1];
    }
    if(N[j] == H[i]) {
      if(j == n-1) {
        ret.push_back(i-n+1);
        j = pi[j];
      }
      else {
        j++;
      }
    }
  }
  return ret;
}

int shift(string origin, string target)
{
  return kmp(origin+origin, target)[0];
}

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    scanf("%d", &_N);
    vector<string> v(_N+1);
    for(int i=0; i<_N+1; i++) {
      cin >> v[i];
    }

    int ret = 0;
    for(int i=0; i<_N; i++) {
      if(i%2 == 0) {
        ret += shift(v[i+1], v[i]);
      }
      else {
        ret += shift(v[i], v[i+1]);
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}
