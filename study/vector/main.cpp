#include <iostream>
#include <cmath>

using namespace std;

const double PI = 2.0 * acos(0.0);
const double EPSILON = 0;

struct vector2 {
    double x, y;
    
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_){
        
    }
    
    bool operator == (const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    
    // x 좌표를 비교하고 y 좌표를 비교한다
    bool operator < (const vector2& rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    
    // x 좌표끼리 y 좌표끼리 더한 후 vector2를 반환한다
    vector2 operator + (const vector2& rhs) const {
        return vector2(x + rhs.x, y + rhs.y);
    }
    
    // x좌표끼리 y 좌표끼리 뺀 후 vector2를 반환한다
    vector2 operator - (const vector2& rhs) const {
        return vector2(x - rhs.x, y - rhs.y);
    }
    
    // x좌표와 y좌표에 각각 rhs배 만큼 한 vector2를 반환한다
    vector2 operator * (double rhs) const {
        return vector2(x * rhs, y * rhs);
    }
    
    // hypot : square root (x*x + y*y)
    // 원점(0, 0)에서부터 (x, y)까지의 거리를 반환한다
    double norm() const {
        return hypot(x, y);
    }
    
    // 원점과 (x, y)를 포함하는 직선의 단위벡터를 반환한다
    vector2 normalize() const {
        return vector2(x / norm(), y / norm());  
    }
    
    // fmod : double형 나눗셈의 나머지
    // atan2 : vector가 x축과 이루는 각을 반환한다 : atan2(y, x) : return -PI ~ PI
    // 반시계 방향을 유지하기 위해 2*PI를 더해준다
    // x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도 : return 0 ~ 1
    double polar() const {
        return fmod(atan2(y, x) + 2*PI, 2*PI);
    }
    
    // vector 내적
    // 직각 확인(내적 값 0), 벡터의 사영
    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    
    // vector 외적
    // = |a|*|b|sin쎄타
    // 면적 계산하기(평행사변형의 넓이 / 2 = 삼각형의 넓이),
    // 두 벡터의 방향 판별 : axb 값이 양수라면 b는 a에서 반시계방향으로 180도 안에 있다
    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
    
    // 이 벡터를 rhs에 사영한 결과
    // this 벡터를 rhs 벡터에 끼워맞춘다
    // 사영 벡터 크기 = |a|cos쎄타 = (a*b) / |b| = a*b/|b| = a*b단위벡터
    // 사영 벡터 방향 = b단위벡터
    vector2 project(const vector2& rhs) const {
        // rhs 벡터의 단위벡터
        vector2 r = rhs.normalize();
        // rhs 단위벡터와 this 벡터를 내적하고 rhs 단위벡터를 곱해준다(방향).
        return r * r.dot(*this);
    }
};

// 원점을 기준으로 점 b가 점 a의 반시계 방향에 있으면 양수, 시계 방향이면 음수를 반환한다
// 외적 결과가 0이면 vector a(OA)와 b(OB)는 평행하다
double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}

// 점p를 기준으로 점b가 점a의 반시계 방향에 있으면 양수, 시계 방향이면 음수를 반환한다
// 외적 결과가 0이면 vector a-p(PA)와 b-p(PB)는 평행하다
double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a-p, b-p);
}

// 점 a와 b를 포함하는 직선과 c, d를 포함하는 직선의 교차여부를 반환하고 교차한다면 교차한 점을 x에 입력하는 함수
bool lineIntersection(vector2 a, vector2 b,
                     vector2 c, vector2 d, vector2& x) {
    // 두 직선을 외적한다
    double det = (b - a).cross(d - c);
    // 외적 결과가 0이면(EPSILON보다 작으면) 두 직선은 평행한 관계기 때문에 false를 반환한다
    if(fabs(det) < EPSILON) return false;
    // 두 직선은 한 점에서 교차하고 연립방정식을 통해 교차하는 좌표 x를 구한다
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

// 선분(a,b)와 선분(c,d)가 평행할 때, 한 점에서 겹치는지 확인한다
bool parallelSegments(vector2 a, vector2 b,
                     vector2 c, vector2 d, vector2& p) {
    // a와 c가 선분의 초점에 오도록 만든다
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);
    // ccw(a, b, c) != 0 : a, b를 포함하는 직선과 a, c를 포함하는 직선이 평행하지 않다. 즉 점 b, c는 같은 직선에 없다 따라서 두 선분은 평행하지 않다
    // b < c : 선분(c,d)의 초점보다 아래에 선분(a,b)의 종점이 있다. 두 선분은 평행하지만 서로 만나지 않는다
    // d < a : 선분(a,b)의 초점보다 아래에 선분(c,d)의 종점이 있다. 두 선분은 평행하지만 서로 만나지 않는다
    if(ccw(a, b, c) != 0 || b < c || d < a) {
        return false;
    }
    // 선분(ab)보다 선분(cd)가 원점에서 더 멀리 떨어져있다.
    if(a < c) {
        p = c;
    } else {
        p = a;
    }
    return true;
}

// 점 p가 선분(ab)에 있는지 확인한다
// 점 a와 b를 직사각형의 시작점과 끝점으로 본다면 점p가 직사각형 ab안에 있는지 확인할 수 있다
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
    if(b < a) {
        swap(a, b);
    }
    // p == a : 점 p가 직사각형의 시작점 a에 있다
    // p == b : 점 p가 직사각형의 끝점 b에 있다
    // a < p && p < b : 점 p가 직사각형 내부에 있다
    return p == a || p == b || (a < p) && (p < b);
}

// 선분(a,b)와 선분(c,d)의 교점을 p에 반환한다
// 교점이 여러개 일경우(겹칠 경우) 아무 점이나 반환한다
// 교차하지 않으면 false를 반환한다
bool segmentIntersection(vector2 a, vector2 b,
                        vector2 c, vector2 d, vector2& p) {
    // 두 선분이 평행할 경우에만 조건문을 실행한다
    // p에는 두 선분의 교차점이 입력된다
    if(!lineIntersection(a, b, c, d, p)) {
        // 두 선분이 만날 경우 p에 입력하는 함수
        return parallelSegments(a, b, c, d, p);
    }
    // 점 p가 선분 (a,b)에 있고 점 p가 선분 (c,d)에 있으면 두 선분은 p에서 교차한다
    return inBoundingRectangle(p, a, b) &&
        inBoundingRectangle(p, c, d);
}

// 두 선분(a,b), (c,d)의 교차점이 있는지 여부를 판단한다
bool segmentIntersects(vector2 a, vector2 b,
                      vector2 c, vector2 d) {
    // ab == 0 : ccw(a, b, c)가 0이라면 점 a, b, c는 한 직선에 있다 따라서 ab == 0은 4개의 점 중 3개 점이 한 직선상에 있다는 걸 의미한다
    // ab > 0 : 점 c와 d가 직선 ab를 기준으로 같은 공간에 있는 것을 의미한다
    // ab < 0 : 점 c와 d가 직선 ab를 기준으로 다른 공간에 있는 것을 의미한다
    double ab = ccw(a, b, c) * ccw(a, b, d);
    double cd = ccw(c, d, a) * ccw(c, d, b);
    
    // 두 선분이 한 직선에 있거나 끝점이 겹칠 경우
    if(ab == 0 && cd == 0) {
        if(b < a) {
            swap(a, b);
        }
        if(d < c) {
            swap(c, d);
        }
        // 두 선분이 평행할 경우, 선분의 초점 c 또는 a가 다른 선분의 종점 b 또는 d보다 멀리 있으면 두 선분은 평행하지만 교차점은 없다
        // 두 선분이 평행하지 않을 경우, ab와 cd가 모두 0이 되기 위해서는 ab의 관점에서 점 c 또는 d가 같은 직선에 있고 cd의 관점에서도 a 또는 b가 같은 직선에 있어야 하는데 이를 만족하면서 아래 조건식을 만족하는 경우는 끝점이 겹치는 경우밖에 없다
        return !(b < c || d < a);
    }
    // ab와 cd가 모두 음수라면 두 선분은 교차한다
    // ab 또는 cd 둘 중 하나가 0인 경우는 두 선분 중 하나의 끝점이 다른 선분에 닿아있을 경우이다 따라서 이 경우에도 교차한다고 볼 수 있다
    return ab <= 0 && cd <= 0;
}

// 점 p에서 직선 ab에 수선을 내렸을 때 벡터를 반환한다
// 이는 벡터 AP를 AB에 사영한 결과와 같다
vector2 perpendicularFoot(vector2 p, vector2, a, vector2 b) {
    return a + (p - a).project(b - a);
}

// 점 p에서 직선 ab까지의 거리를 구한다
// 점 p에서 직선 ab에 수선을 내렸을 때 그 점을 q라고 하면 거리는 vector | AQ - AP |로 구할 수 있다.
double pointToLine(vector2 p, vector2 a, vector2 b) {
    return (p - perpendicularFoot(p, a, b)).norm();
}

int main()
{
    vector2 a = vector2(5.0, 3.0);
    vector2 b = vector2(2.0, 0.0);
    cout << "a 크기 : " << a.norm() << endl;
    cout << "b 크기 : " << b.norm() << endl;
    
    cout << "a가 x축과 이루는 각도 : " << a.polar() << endl;
    cout << "b가 x축과 이루는 각도 : " << b.polar() << endl;
    
    cout << "a와 b의 내적 값 : " << a.dot(b) << endl;
    vector2 pro = a.project(b);
    cout << "a를 b에 사영한 vector x: " << pro.x << " y: " << pro.y << endl;
    return 0;
}