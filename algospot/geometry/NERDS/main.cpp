#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct vector2 {
    double x, y;
    explicit vector2(double x_=0, double y_=0) : x(x_), y(y_) {
        
    }
    
    bool operator < (const vector2& rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
    
    vector2 operator + (const vector2& rhs) const {
        return vector2(x+rhs.x, y+rhs.y);
    }
    
    vector2 operator - (const vector2& rhs) const {
        return vector2(x-rhs.x, y-rhs.y);
    }
    
    vector2 operator * (double rhs) const {
        return vector2(rhs*x, rhs*y);
    }
    
    double cross(const vector2& rhs) const {
        return x*rhs.y - y*rhs.x;
    }
    
    bool isEqual(const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    
    double norm() const {
        return hypot(x, y);
    }
};

vector2 getMostLeft(vector<vector2>& poly);
vector2 getNextEdge(vector<vector2>& poly, vector2& edge);
double ccw(vector2& edge, vector2& a, vector2& b);
bool isInside(vector2& edge, vector<vector2>& poly);
bool polygonIntersects(vector<vector2>& p, vector<vector2>& q);

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        vector<vector2> nerds;
        vector<vector2> notNerds;
        vector<vector2> nerdsPolygon;
        vector<vector2> nNerdsPolygon;
        int num;
        bool result;
        cin >> num;
        for(int i=0; i<num; i++) {
            int n, s, t;
            cin >> n >> s >> t;
            if(n == 1) nerds.push_back(vector2(s, t));
            else notNerds.push_back(vector2(s, t));
        }
        // nerd 선물포장
        // 가장 왼쪽점을 찾는다
        vector2 mostLeft = getMostLeft(nerds);
        nerdsPolygon.push_back(mostLeft);
        
         // edge들을 찾는다
        vector2 edge = getNextEdge(nerds, mostLeft);
        while(!edge.isEqual(mostLeft)) {
            nerdsPolygon.push_back(edge);
            edge = getNextEdge(nerds, nerdsPolygon.back());
        }
        
        // notNerd 선물포장
        vector2 nMostLeft = getMostLeft(notNerds);
        nNerdsPolygon.push_back(nMostLeft);
        
        vector2 nEdge = getNextEdge(notNerds, nMostLeft);
        while(!nEdge.isEqual(nMostLeft)) {
            nNerdsPolygon.push_back(nEdge);
            nEdge = getNextEdge(notNerds, nNerdsPolygon.back());
        }
        
        // 두 다각형이 겹치는지 확인한다
        result = polygonIntersects(nerdsPolygon, nNerdsPolygon);
        
        if(!result) cout << "THEORY HOLDS" << endl;
        else cout << "THEORY IS INVALID" << endl;
    }
    return 0;
}

vector2 getMostLeft(vector<vector2>& poly)
{
    vector2 mostLeft = vector2(poly[0].x, poly[0].y);
    for(int i=1; i<poly.size(); i++) {
        if(mostLeft.x > poly[i].x) {
            mostLeft = poly[i];
        }
    }
    return mostLeft;
}

double ccw(vector2& edge, vector2& a, vector2& b)
{
    // b-edge가 왼쪽에 있으면 양수
    return (a-edge).cross(b-edge);;
}

// 선물 포장을 위해 edge에 가장 왼쪽에 있는 다음 지점을 찾는다
vector2 getNextEdge(vector<vector2>& poly, vector2& edge)
{
    vector2 nextEdge = poly[0];
    for(int i=1; i<poly.size(); i++) {
        double r = ccw(edge, nextEdge, poly[i]);
        double dist = (nextEdge - edge).norm() - (poly[i] - edge).norm();
        if(r > 0 || (r == 0 && dist < 0)) {
            nextEdge = poly[i];
        }
    }
    return nextEdge;
}

// poly 다각형 안에 edge가 있는지 확인한다
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

// 선분 ab와 선분 cb가 겹치는지 확인한다
bool segmentIntersects(vector2 a, vector2 b,
                      vector2 c, vector2 d) {
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d, a) * ccw(c, d, b);
    
    if(ab == 0 && cd == 0) {
        if(b < a) {
            swap(a, b);
        }
        if(d < c) {
            swap(c, d);
        }
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

// 두 다각형이 겹치는지 확인한다
bool polygonIntersects(vector<vector2>& p, vector<vector2>& q)
{
    int n = p.size(), m = q.size();
    if(isInside(p[0], q) || isInside(q[0], p)) return true;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(segmentIntersects(p[i], p[(i+1)%n], q[j], q[(j+1)%m])) {
                return true;
            }
        }
    }
    return false;
}