#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct vector2 {
    double x, y;

    explicit vector2(double x_=0, double y_=0) : x(x_), y(y_) {

    }

    bool operator == (vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool operator < (vector2& rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }

    vector2 operator + (vector2& rhs) const {
        return vector2(x+rhs.x, y+rhs.y);
    }

    vector2 operator - (vector2& rhs) const {
        return vector2(x-rhs.x, y-rhs.y);
    }

    vector2 operator * (double rhs) const {
        return vector2(rhs*x, rhs*y);
    }

    double norm() const {
        return hypot(x,y);
    }

    vector2 normalize() const {
        return vector2(x / norm(), y / norm());
    }

    double dot(vector2& rhs) const {
        return x*rhs.x + y*rhs.y;
    }

    double cross(vector2& rhs) const {
        return x*rhs.y - y*rhs.x;
    }

};

double cw(vector2 a, vector2 b);
// 선택되지 않은 점 중에서 전에 선택된 점에 가장 왼쪽에 있는 점을 찾는다
double ccw(vector2 p, vector2 a, vector2 b);
vector2 getNextLeft(vector<vector2>& p, vector2 mostLeft);
vector2 getMostLeft(vector<vector2>& p);
int main()
{
    int num;
    vector<vector2> p;
    cin >> num;
    for(int i=0; i<num; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back(vector2(x,y));
    }
    // 포장하는 점 vector
    vector<vector2> gift;
    vector2 mostLeft = getMostLeft(p);
    gift.push_back(mostLeft);
    vector2 nextLeft = getNextLeft(p, mostLeft);
    // 가장 왼쪽점을 초기 점으로 찾을때까지 반복한다
    while (!(mostLeft == nextLeft)) {
        gift.push_back(nextLeft);
        nextLeft = getNextLeft(p, gift.back());
    }

    cout << gift.size() << endl;

    return 0;
}

double cw(vector2 a, vector2 b)
{
    return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b)
{
    return cw(a-p, b-p);
}

vector2 getMostLeft(vector<vector2>& p)
{
    vector2 ret = p[0];
    for(int i=1; i<p.size(); i++) {
        if(ret.x > p[i].x) {
            ret = p[i];
        }
    }
    return ret;
}

vector2 getNextLeft(vector<vector2>& p, vector2 mostLeft)
{
    vector2 nextLeft = p[0];
    for(int i=1; i<p.size(); i++) {
        double left = ccw(mostLeft, nextLeft, p[i]);
        double dist = (nextLeft-mostLeft).norm() - (p[i]-mostLeft).norm();
        if(left > 0 || (dist < 0 && left == 0)) {
            nextLeft = p[i];
        }
    }
    return nextLeft;
}