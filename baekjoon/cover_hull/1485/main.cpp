#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct vector2 {
    int x;
    int y;
    
    vector2(int x_=0, int y_=0) : x(x_), y(y_) {
        
    }
    
    bool operator == (const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    
    bool operator < (const vector2& rhs) const {
        return y != rhs.y ? y < rhs.y : x < rhs.x;
    }
    
    vector2 operator + (const vector2& rhs) const {
        return vector2(x+rhs.x, y+rhs.y);
    }
    
    vector2 operator - (const vector2& rhs) const {
        return vector2(x-rhs.x, y-rhs.y);
    }
    
    double norm() const {
        return hypot(x,y);
    }
    
};

int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        vector<vector2> square(4);
        for(int i=0; i<4; i++) {
            int x,y;
            scanf("%d %d", &x, &y);
            vector2 v = vector2(x,y);
            square[i] = v;
        }
        sort(square.begin(), square.end());
        double d = (square[0] - square[1]).norm();
        if((square[1] - square[3]).norm() == d &&
          (square[3] - square[2]).norm() == d &&
          (square[2] - square[0]).norm() == d) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}