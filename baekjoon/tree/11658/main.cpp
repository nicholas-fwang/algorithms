#include <cstdio>

using namespace std;

long long a[1025][1025];
long long tree[1025][1025];
int N;

long long sum(int row, int col) {
  long long ret = 0;
  for(; row; row -= (row&-row)) {
    for(int c = col; c; c -= (c&-c)) {
      ret += tree[row][c];
    }
  }
  return ret;
}

void update(int row, int col, long long diff) {
  for(; row<=N; row += (row&-row)) {
    for(int c = col; c<=N; c += (c&-c)) {
      tree[row][c] += diff;
    }
  }
}

int main()
{

  int m;
  scanf("%d %d", &N, &m);

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%lld", &a[i][j]);
      update(i, j, a[i][j]);
    }
  }

  for(int i=0; i<m; i++) {
    int w;
    scanf("%d", &w);

    if(w == 0) {
      int x, y;
      long long c;
      scanf("%d %d %lld", &x, &y, &c);
      long long diff = c-a[x][y];
      a[x][y] = c;
      update(x, y, diff);
    }
    else if(w == 1) {
      int r1,c1;
      int r2,c2;
      scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
      long long ret = sum(r2,c2) - sum(r1-1,c2) - sum(r2,c1-1) + sum(r1-1,c1-1);
      printf("%lld\n", ret);
    }
  }
  return 0;
}
