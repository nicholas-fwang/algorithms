#include <iostream>
#include <cmath>

using namespace std;

double polyX[10000];
double polyY[10000];

int main()
{
    int num;
    double area = 0.0;
    cin >> num;
    for(int i=0; i<num; i++) {
        cin >> polyX[i] >> polyY[i];
    }
    
    // 다각형 꼭지점 수 만큼 반복문을 수행한다
    for(int i=0; i<num; i++) {
        // 다각형의 꼭지점 index는 i와 j로 나타낸다
        // j는 i가 num-1에 도달했을 때 0으로 만들어야 하기 때문에 %연산을 사용했다
        int j = (i + 1) % num;
        // 두 vector를 외적해 평행사변형 넓이를 구하고 2로 나누어 삼각형 넓이를 구한다
        area += (polyX[i]*polyY[j] - polyX[j]*polyY[i]) / 2;
    }
    // 절대값을 취한다
    area = fabs(area);
    // 소수점 첫번째 자리에서 반올림한다
    cout << fixed;
    cout.precision(1);
    cout << area << endl;
    
    return 0;
}
