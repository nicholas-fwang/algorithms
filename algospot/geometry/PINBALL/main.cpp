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
        // a에서 시작해서 p방향으로 공이 이동한다
        vector2 a = vector2(bx, by);
        vector2 p = vector2(dx, dy).normalize();

        for(int i=0; i<n; i++) {
            double x, y;
            int rad;
            cin >> x >> y >> rad;
            c[i] = vector2(x, y);
            // 공의 지름 -1 --> 장애물 지름 +1
            r[i] = rad+1;
        }

        // 100번 이상 부딪히면 끝
        while(cnt < 100) {
            // 충돌하는 장애물 찾기
            int crushed = -1;
            double t = INFITY;
            for(int i=0; i<n; i++) {
                double tmp = crush(a, p, c[i], r[i]);
                if(t > tmp) {
                    t = tmp;
                    // i번째 장애물에 부딪힘
                    crushed = i;
                }
            }
            if(crushed == -1) break;
            cout << crushed << " ";
            cnt++;
            // 반사
            vector2 q = a + p*t;
            vector2 d = reflect(p, q-c[crushed]);
            // 반사된 지점 a, 방향 p
            a = q;
            p = d;
        }
        cout << endl;

    }
    return 0;
}

double crush(vector2 s, vector2 p, vector2 center, int r)
{
    /// |cn - f(t)| = rn 근의 방정식
    // 원의 중심(cn)과 공의 이동 방정식(f(t))이 원의 지름(rn)이 된다.
    double a = p.dot(p);
    double b = 2*(s-center).dot(p);
    double c = center.dot(center)+s.dot(s)-r*r-2*center.dot(s);

    // < 0 허근 : 안부딪힘
    double d = b*b - 4*a*c;

    // 전혀 안부딪힘
    if(d < 0) {
        return INFITY;
    }

    // 부딪힌 t초 구하기
    // t가 음수라면 과거에 부딪힘
    // t가 양수라면 더 작은 t에서 부딪힘
    double solv = (-b - sqrt(d)) / 2*a;
    if(solv < 0) {
        return INFITY;
    } else {
        return solv;
    }
}

vector2 reflect(vector2 p, vector2 b)
{
    return (p-p.project(b)*2).normalize();
}
