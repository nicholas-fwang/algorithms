#include <cstdio>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int oo = 0x3f3f3f3f;
const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

string map[51];
int visited[51][51][4];
int N;

int sr, sc;
int er, ec;

bool inRange(int r, int c)
{
  if(r >=0 && c >= 0 && r < N && c < N) return true;
  return false;
}

int main()
{
  scanf("%d", &N);
  sr = -1;
  sc = -1;
  for(int i=0; i<N; i++) {
    cin >> map[i];
    for(int j=0; j<N; j++) {
      if(map[i][j] == '#') {
        if(sr == -1) {
          sr = i;
          sc = j;
        }
        else {
          er = i;
          ec = j;
        }
      }
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      for(int z=0; z<4; z++) {
        visited[i][j][z] = oo;
      }
    }
  }

  queue<pair<pair<int, int>, int> > q;
  for(int i=0; i<4; i++) {
    q.push(make_pair(make_pair(sr, sc), i));
    visited[sr][sc][i] = 0;
  }
  while(!q.empty()) {
    int r = q.front().first.first;
    int c = q.front().first.second;
    int d = q.front().second;
    q.pop();
    int _r = r + dr[d];
    int _c = c + dc[d];
    if(!inRange(_r, _c)) continue;
    if(map[_r][_c] == '*') continue;
    else if(map[_r][_c] == '!') {
      if(visited[_r][_c][d] > visited[r][c][d]) {
        visited[_r][_c][d] = visited[r][c][d];
        q.push(make_pair(make_pair(_r, _c), d));
      }
      if(visited[_r][_c][(d+1)%4] > visited[r][c][d] + 1) {
        visited[_r][_c][(d+1)%4] = visited[r][c][d] + 1;
        q.push(make_pair(make_pair(_r, _c), (d+1)%4));
      }
      if(visited[_r][_c][(d+3)%4] > visited[r][c][d] + 1) {
        visited[_r][_c][(d+3)%4] = visited[r][c][d] + 1;
        q.push(make_pair(make_pair(_r, _c), (d+3)%4));
      }
    }
    else if(map[_r][_c] == '.') {
      if(visited[_r][_c][d] > visited[r][c][d]) {
        visited[_r][_c][d] = visited[r][c][d];
        q.push(make_pair(make_pair(_r, _c), d));
      }
    }
    else if(map[_r][_c] == '#') {
      if(visited[_r][_c][d] > visited[r][c][d]) {
        visited[_r][_c][d] = visited[r][c][d];
      }
    }
  }

  int ret = oo;
  for(int i=0; i<4; i++) {
    ret = min(ret, visited[er][ec][i]);
  }
  printf("%d\n", ret);
  return 0;
}
