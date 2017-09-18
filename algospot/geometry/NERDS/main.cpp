#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct vector2 {
  int x,y;

  vector2(int _x=0, int _y=0) : x(_x), y(_y) {}

  bool operator == (const vector2& rhs) const {
    return x == rhs.x && y == rhs.y;
  }

  bool operator < (const vector2& rhs) const {
    return x != rhs.x ? x < rhs.x : y < rhs.y;
  }

  vector2 operator + (const vector2& rhs) const {
    return vector2(x+rhs.x, y+rhs.y);
  }

  vector2 operator - (const vector2& rhs) const {
    return vector2(x-rhs.x, y-rhs.y);
  }

  vector2 operator * (int rhs) const {
    return vector2(rhs*x, rhs*y);
  }

  double norm() const {
    return hypot(x,y);
  }

  vector2 normalize() const {
    return vector2(x/norm(), y/norm());
  }

  double dot(const vector2& rhs) const {
      return x * rhs.x + y * rhs.y;
  }

  double cross(const vector2& rhs) const {
      return x * rhs.y - rhs.x * y;
  }
};

double ccw(vector2 a, vector2 b) {
  return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
  return ccw(a-p, b-p);
}

bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
  double ab = ccw(a, b, c) * ccw(a, b, d);
  double cd = ccw(c, d, a) * ccw(c, d, b);

  if(ab == 0 && cd == 0) {
    if(b < a) swap(a,b);
    if(d < c) swap(c,d);

    return !((b < c) || (d < a));
  }

  return ab <= 0 && cd <= 0;
}

typedef vector<vector2> polygon;

polygon wrapGift(vector<vector2>& points) {
  int n = points.size();
  polygon ret;
  vector2 p = *min_element(points.begin(), points.end());
  ret.push_back(p);
  while(true) {
    vector2 ph = ret.back();
    vector2 next = points[0];
    for(int i=1; i<n; i++) {
      double cross = ccw(ph, next, points[i]);
      double dist = (next-ph).norm() - (points[i]-ph).norm();
      if(cross > 0 || (cross == 0 && dist < 0)) {
        next = points[i];
      }
    }
    if(next == p) break;
    ret.push_back(next);
  }
  return ret;
}

bool isInside(vector2 q, const vector<vector2>& p)
{
	int crosses = 0;
	for(int i=0; i < p.size(); i++)
	{
		int j = (i + 1) % p.size();

		if((p[i].y > q.y) != (p[j].y > q.y))
		{
			double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if(q.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}

bool polygonIntersects(polygon& p1, polygon& p2) {
  int n1 = p1.size();
  int n2 = p2.size();

  if(isInside(p1[0], p2) || isInside(p2[0], p1)) return true;

  for(int i=0; i<n1; i++) {
    for(int j=0; j<n2; j++) {
      vector2 a = p1[i];
      vector2 b = p1[(i+1)%n1];
      vector2 c = p2[j];
      vector2 d = p2[(j+1)%n2];
      if(segmentIntersects(a,b,c,d)) return true;
    }
  }
  return false;
}

int main()
{
  int testCase;
  scanf("%d", &testCase);
  for(int tc=1; tc<=testCase; tc++) {
    int N;
    vector<vector2> p1,p2;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
      int type, x, y;
      scanf("%d %d %d", &type, &x, &y);
      if(type == 0) {
        p1.push_back(vector2(x,y));
      } else {
        p2.push_back(vector2(x,y));
      }
    }
    polygon a = wrapGift(p1);
    polygon b = wrapGift(p2);
    if(polygonIntersects(a,b)) {
      printf("THEORY IS INVALID\n");
    } else {
      printf("THEORY HOLDS\n");
    }
  }
  return 0;
}
