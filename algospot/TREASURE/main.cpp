#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const double EPSILON = 0.001;

struct vector2 {
    double x, y;
    
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_){
        
    }
    
    bool operator == (const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    
    bool operator < (const vector2& rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    
    vector2 operator + (const vector2& rhs) const {
        return vector2(x + rhs.x, y + rhs.y);
    }
    
    vector2 operator - (const vector2& rhs) const {
        return vector2(x - rhs.x, y - rhs.y);
    }
    
    vector2 operator * (double rhs) const {
        return vector2(x * rhs, y * rhs);
    }
    
    double norm() const {
        return hypot(x, y);
    }
    
    vector2 normalize() const {
        return vector2(x / norm(), y / norm());  
    }
    
    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    
    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
    
    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};

double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a-p, b-p);
}

bool lineIntersection(vector2 a, vector2 b,
                     vector2 c, vector2 d, vector2& x) {
    double det = (b - a).cross(d - c);
    if(fabs(det) < EPSILON) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

bool isInside(vector2& edge, vector<vector2>& poly)
{
    int crosses = 0;
    for(int i=0; i<poly.size(); i++) {
        int j = (i + 1) % poly.size();
        if((poly[i].y > edge.y) != (poly[j].y > edge.y)) {
            double atX = (poly[j].x - poly[i].x) * (edge.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x;
            if(edge.x < atX) {
                crosses++;
            }
        }
    }
    return crosses % 2 > 0;
}

// 직사각형의 각 변을 지나가는 직선들로 다각형 점들의 교집합을 구한다
vector<vector2> intersectionPolygon(double x1, double y1, double x2, double y2, vector<vector2>& p);
// a, b를 지나는 직선의 왼쪽에 있거나 교차하는 다각형의 점을 구한다
vector<vector2> cutPoly(vector<vector2>& p, vector2& a, vector2& b);
// 시계 반대방향의 vector p를 이용해 다각형의 넓이를 구한다
double getArea(vector<vector2> p);
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        double x1, y1, x2, y2, n;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        vector<vector2> p;
        for(int i=0; i<n; i++) {
            double px, py;
            cin >> px >> py;
            p.push_back(vector2(px, py));
        }
        
        vector<vector2> poly = intersectionPolygon(x1, y1, x2, y2, p);
        
        cout << fixed;
        cout.precision(10);
        cout << getArea(poly) << endl;
    }
    return 0;
}

vector<vector2> cutPoly(vector<vector2>& p, vector2& a, vector2& b)
{
    int n = p.size();
    vector<bool> inside(n);
    for(int i=0; i<n; i++) {
        inside[i] = ccw(a, b, p[i]) >= 0;
    }
    vector<vector2> ret;
    for(int i=0; i<n; i++) {
        int j = (i+1) % n;
        if(inside[i]) {
            ret.push_back(p[i]);
        }
        if(inside[i] != inside[j]) {
            vector2 tmp;
            lineIntersection(p[i], p[j], a, b, tmp);
            ret.push_back(tmp);
        }
    }
    return ret;
}

vector<vector2> intersectionPolygon(double x1, double y1, double x2, double y2, vector<vector2>& p) {
    vector2 a(x1,y1), b(x2,y1), c(x2,y2), d(x1,y2);
    vector<vector2> ret = cutPoly(p, a, b);
    ret = cutPoly(ret, b, c);
    ret = cutPoly(ret, c, d);
    ret = cutPoly(ret, d, a);
    return ret;
}

double getArea(vector<vector2> p)
{
    double ret=0.0;
    int n = p.size();
    for(int i=0; i<n; i++) {
        int j = (i+1) % n;
        ret += p[i].cross(p[j]) / 2;
    }
    return ret;
}