#include <iostream>
#include <string.h>
#include <limits.h>

#define MAX(a,b) a>b ? a:b

using namespace std;

int a[100], b[100];
int cache[101][101];
int a_, b_;

int jlis(int indexA, int indexB);
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        cin >> a_ >> b_;
        for(int i=0; i<a_; i++) {
            int tmp;
            cin >> tmp;
            a[i] = tmp;
        }
        
        for(int i=0; i<b_; i++) {
            int tmp;
            cin >> tmp;
            b[i] = tmp;
        }
    
        memset(cache, -1, sizeof(cache));
        
        int length = 0;
        int A,B;
        for(int i=-1; i<a_; i++) {
            for(int j=-1; j<b_; j++) {
                length = MAX(length, jlis(i, j));  
            }
        }
        cout << length << endl;
    }
    return 0;
}

int jlis(int indexA, int indexB)
{
    int& ret = cache[indexA+1][indexB+1];
    if(ret != -1) {
        return ret;
    }
    // index가 -1인 경우에는 길이가 0이다
    ret = 0;
    // index로 -1를 넣는 이유는 b의 0번째 값보다 더 작은 값이 a에 있을 경우 이것은 반복문 내 조건에 만족하지 않기 때문에 재귀식을 호출하지 못한다 input example 1을 보면 a[1] = 2는 b[0] = 3보다 작기 때문에 재귀식을 호출 하지 않지만 실제 답은 1, 2, 3, 4, 7이 된다. 즉 2일 때 불려야 하지만 3보다 작기때문에 안 불린 케이스가 된다. 따라서 -1부터 index를 넣어주어 b[-1] = -무한대를 가정했다
    int initA = indexA == -1 ? INT_MIN : a[indexA];
    int initB = indexB == -1 ? INT_MIN : b[indexB];
    int initValue = MAX(initA, initB);
    for(int i=indexA+1; i<a_; i++) {
        if(initValue < a[i]) {
            ret = MAX(ret, jlis(i, indexB)+1);
        }
    }
    
    for(int i=indexB+1; i<b_; i++) {
        if(initValue < b[i]) {
            ret = MAX(ret, jlis(indexA, i)+1);
        }
    }
    
    return ret;
}