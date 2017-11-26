#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string s;

struct Comparator {
  const vector<int>& group;
  int t;
  Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {
  }

  bool operator () (int a, int b) {
    if(group[a] != group[b]) return group[a] < group[b];
    return group[a+t] < group[b+t];
  }
};

vector<int> getSA(const string& s) {
  int n = s.size();

  int t = 1;
  vector<int> group(n+1);
  for(int i=0; i<n; i++) group[i] = s[i];
  group[n] = -1;
  vector<int> perm(n);
  for(int i=0; i<n; i++) perm[i] = i;
  while(t < n) {
    Comparator compareUsing2T(group, t);
    sort(perm.begin(), perm.end(), compareUsing2T);
    t *= 2;
    if(t >= n) break;
    vector<int> newGroup(n+1);
    newGroup[n] = -1;
    newGroup[perm[0]] = 0;
    for(int i=1; i<n; i++) {
      if(compareUsing2T(perm[i-1], perm[i])) {
        newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
      }
      else {
        newGroup[perm[i]] = newGroup[perm[i-1]];
      }
    }
    group = newGroup;
  }
  return perm;
}

vector<int> getLCP(vector<int>& sa)
{
  int n = s.size();
  vector<int> lcp(n, 0);
  for(int i=1; i<sa.size(); i++) {
    int cp = 0;
    int j = sa[i];
    int k = sa[i-1];
    while(j<s.size() && k<s.size() && s[j] == s[k]) {
      ++j; ++k; ++cp;
    }
    lcp[i] = cp;
  }
  return lcp;
}

int main()
{
  cin >> s;
  vector<int> sa = getSA(s);
  vector<int> lcp = getLCP(sa);
  for(int i=0; i<sa.size(); i++) {
    printf("%d ", sa[i]+1);
  }
  printf("\n");
  printf("x ");
  for(int i=1; i<lcp.size(); i++) {
    printf("%d ", lcp[i]);
  }
  printf("\n");
  return 0;
}
