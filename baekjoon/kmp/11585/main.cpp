#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int N;

vector<int> getpi(string needle)
{
  int n = needle.size();

  vector<int> pi(n, 0);

  int j=0;
  for(int i=1; i<n; i++) {
    while(j>0 && needle[i] != needle[j]) {
      j = pi[j-1];
    }
    if(needle[i] == needle[j]) {
      pi[i] = ++j;
    }
  }
  return pi;
}

vector<int> kmp(string haystack, string needle)
{
  int h = haystack.size();
  int n = needle.size();

  vector<int> pi = getpi(needle);
  vector<int> ret;

  int j=0;
  for(int i=0; i<h-1; i++) {
    while(j>0 && haystack[i] != needle[j]) {
      j = pi[j-1];
    }
    if(haystack[i] == needle[j]) {
      j++;
      if(j == n) {
        ret.push_back(i-n+1);
        j = pi[j-1];
      }
    }
  }
  return ret;
}

int gcd(int a, int b)
{
  if(a%b == 0) return b;
  else return gcd(b, a%b);
}

int main()
{
  string haystack, needle;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    char c;
    cin >> c;
    haystack.push_back(c);
  }
  for(int i=0; i<N; i++) {
    char c;
    cin >> c;
    needle.push_back(c);
  }
  haystack += haystack;
  vector<int> ret = kmp(haystack, needle);
  int g = gcd(N, ret.size());
  printf("%d/%d\n", ret.size()/g, N/g);

  return 0;
}
