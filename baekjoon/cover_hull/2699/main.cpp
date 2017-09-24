#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct vector2 {
  int x,y;

  vector2(int _x, int _y) :x(_x), y(_y) {}

  bool operator == (const vector2& rhs) const {
    return x==rhs.x && y==rhs.y;
  }

  bool operator < (const vector2& rhs) const {
    return y != rhs.y ? y < rhs.y : x > rhs.x;
  }

  vector2 operator + (const vector2& rhs) const {
    return vector2(x + rhs.x, y + rhs.y);
  }

  vector2 operator - (const vector2& rhs) const {
    return vector2(x - rhs.x, y - rhs.y);
  }

  vector2 operator * (double rhs) const {
    return vector2(rhs*x, rhs*y);
  }

  double norm() const {
    return hypot(x,y);
  }

  vector2 normalize() const {
    return vector2(x/norm(), y/norm());
  }

  double dot(vector2& rhs) const {
    return x*rhs.x + y*rhs.y;
  }

  double cross(const vector2& rhs) const {
    return x*rhs.y - y*rhs.x;
  }

};

double cw(vector2 a, vector2 b) {
  return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
  return cw(a-p, b-p);
}

typedef vector<vector2> polygon;
int N;

polygon wrapGift(vector<vector2>& points) {
  int size = points.size();
  polygon ret;
  vector2 p = *max_element(points.begin(), points.end());
  ret.push_back(p);
  while(true) {
    vector2 ph = ret.back();
    vector2 next = points[0];
    for(int i=1; i<size; i++) {
      double cross = ccw(ph, next, points[i]);
      double dist = (next - ph).norm()
                      - (points[i] - ph).norm();

      if(cross > 0 || (cross == 0 && dist < 0)) {
        next = points[i];
      }
    }
    if(next == p) break;
    ret.push_back(next);
  }
  return ret;
}

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    scanf("%d", &N);
    vector<vector2> points;
    for(int i=0; i<N; i++) {
      int x,y;
      scanf("%d %d", &x, &y);
      points.push_back(vector2(x,y));
    }
    polygon ret = wrapGift(points);
    printf("%d\n", (int)ret.size());
    for(int i=0; i<ret.size(); i++) {
      printf("%d %d\n", ret[i].x, ret[i].y);
    }
  }
  return 0;
}
