#include <iostream>
#include <cmath>

const double INFITY = 1e200;

using namespace std;

struct vector2 {
    double x, y;

    explicit vector2(double x_=0, double y_=0): x(x_), y(y_){
    }

    vector2 operator + (const vector2& rhs) const {
        return vector2(x+rhs.x, y+rhs.y);
    }

    vector2 operator - (const vector2& rhs) const {
        return vector2(x-rhs.x, y-rhs.y);
    }

    vector2 operator * (const double rhs) const {
        return vector2(rhs*x, rhs*y);
    }

    double dot(const vector2& rhs) const {
        return x*rhs.x + y*rhs.y;
    }

    double norm() const {
        return hypot(x, y);
    }

    vector2 normalize() const {
        return vector2(x/norm(), y/norm());
    }

    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};


double crush(vector2 s, vector2 p, vector2 center, int r);
vector2 reflect(vector2 p, vector2 b);
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        vector2 c[50];
        int r[50];
        int n, dx, dy;
        int bx, by;
        int cnt = 0;
        cin >> bx >> by >> dx >> dy >> n;
        // 공의 시작지점
        vector2 a = vector2(bx, by);
        // 단위벡터로 만들어야 제대로된 답이 나온다
        vector2 p = vector2(dx, dy).normalize();

        for(int i=0; i<n; i++) {
            double x, y;
            int rad;
            cin >> x >> y >> rad;
            c[i] = vector2(x, y);
            r[i] = rad+1;
        }
        
        while(cnt < 100) {
            // 충돌하는 장애물 찾기
            int crushed = -1;
            double t = INFITY;
            for(int i=0; i<n; i++) {
                double tmp = crush(a, p, c[i], r[i]);
                if(t > tmp) {
                    t = tmp;
                    crushed = i;
                }
            }
            // 공이 어느 장애물에도 부딪히지 않았다
            if(crushed == -1) break;
            cout << crushed << " ";
            cnt++;
            // 반사
            // 공이 충돌한 좌표를 구한다
            vector2 q = a + p*t;
            // 공이 반사되는 단위벡터를 구한다
            vector2 d = reflect(p, q-c[crushed]);
            // 충돌한 좌표가 새로운 시작 지점,
            // 반사되는 단위벡터가 새로운 공의 방향벡터가 된다
            a = q;
            p = d;
        }
        cout << endl;

    }
    return 0;
}

double crush(vector2 s, vector2 p, vector2 center, int r)
{
    // 이차 방정식 ax^2+bx+c=0 형태를 만든다
    double a = p.dot(p);
    double b = 2*(s-center).dot(p);
    double c = center.dot(center)+s.dot(s)-r*r-2*center.dot(s);

    double d = b*b - 4*a*c;

    // 전혀 안부딪힘
    if(d < 0) {
        return INFITY;
    } 

    // 시간t의 근은 무조건 양수 2개가 나와야 된다(또는 양수 중근)
    // 그 중 작은 값만 취하기 때문에 큰 값은 버린다
    double solv = (-b - sqrt(d)) / 2*a;
    // 음수가 하나라도 나오면 공은 장애물에 부딪히지 않는다
    if(solv < 0) {
        return INFITY;
    } else {
        return solv;
    }
}

// 사영을 이용해 반사 방향벡터를 구한다
vector2 reflect(vector2 p, vector2 b)
{
    // 단위벡터로 만들어야 제대로된 답이 나온다
    return (p-p.project(b)*2).normalize();
}
