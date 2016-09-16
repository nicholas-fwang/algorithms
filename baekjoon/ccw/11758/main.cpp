#include <iostream>
#include <cstdio>

using namespace std;

struct vector2 {
    int x,y;
    
    explicit vector2(int x_=0, int y_=0) : x(x_), y(y_) {
        
    }
    
    vector2 operator * (const vector2& rhs) {
        return vector2(x*rhs.x, y*rhs.y);
    }
    
    vector2 operator + (const vector2& rhs) {
        return vector2(x+rhs.x, y+rhs.y);
    }
    
    vector2 operator - (const vector2& rhs) {
        return vector2(x-rhs.x, y-rhs.y);
    }
    
    int cross(const vector2& rhs) {
        return (x*rhs.y - y*rhs.x);
    }
    
};

int ccw(vector2 a, vector2 b);
int ccw(vector2 p, vector2 a, vector2 b);

int main()
{
    int x,y;
    scanf("%d %d", &x, &y);
    vector2 p(x,y);
    scanf("%d %d", &x, &y);
    vector2 a(x,y);
    scanf("%d %d", &x, &y);
    vector2 b(x,y);
    int ret = ccw(p,a,b);
    if(ret == 0) {
        ret = 0;
    } else {
        ret = ret/abs(ret);
    }
    printf("%d\n", ret);
    return 0;
}

int ccw(vector2 a, vector2 b)
{
    return a.cross(b);
}
int ccw(vector2 p, vector2 a, vector2 b)
{
    return ccw(a-p, b-p);
}