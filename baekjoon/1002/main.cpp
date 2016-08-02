#include <iostream>
#include <cmath>

using namespace std;

bool isSameCircle(int x1, int y1, int r1, int x2, int y2, int r2);
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        int x1, y1, r1, x2, y2, r2;
        int result;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        // 원의 중심이 다른 원 안에 있는 경우
        if(d < r1 || d < r2) {
            if(isSameCircle(x1, y1, r1, x2, y2, r2)) {
                // 같은 원인 경우
                result = -1;
            } else if(abs(r1-r2) < d) {
                // 2점이 겹치는 경우
                result = 2;
            } else if(abs(r1-r2) == d) {
                // 내접하는 경우
                result = 1;   
            } else {
                // 서로 닿지 않는 경우
                result = 0;
            }
        }
        // 원의 중심이 다른 원 밖에 있는 경우
        else {
            if(r1+r2 > d) {
                // 2점이 겹치는 경우
                result = 2;
            } else if(r1+r2 == d) {
                // 외접하는 경우
                result = 1;
            } else {
                // 서로 닿지 않는 경우
                result = 0;
            }
        }
        
        cout << result << endl;
    }
    return 0;
}

bool isSameCircle(int x1, int y1, int r1, int x2, int y2, int r2)
{
    if(x1 == x2 && y1 == y2 && r1 == r2) {
        return true;
    }
    return false;
}
