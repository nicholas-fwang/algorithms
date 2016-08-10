#include <iostream>
#include <limits.h>

#define MIN(a,b) a>b ? b:a

using namespace std;

int n[10000];
int sum[10000];
int size;

int getDifficulty(int start, int end);
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        string str;
        cin >> str;
        size = str.size();
        for(int i=0; i<size; i++) {
            n[i] = str[i] - 48;
        }
        // 1~2 자릿수는 난이도 10
        sum[0] = sum[1] = 10;
        // 3~5 자릿수의 난이도 합성은 무조건 10보다 크다
        sum[2] = getDifficulty(0,2);
        sum[3] = getDifficulty(0,3);
        sum[4] = getDifficulty(0,4);
        
        // sum[n] = min(sum[n-3] + (n~2, n)난이도,
        //              sum[n-4] + (n~3, n)난이도,
        //              sum[n-5] + (n~4, n)난이도)
        for(int i=5; i<size; i++) {
            sum[i] = INT_MAX;
            for(int j=i-3; j>=i-5; j--) {
                if(j < 0) continue;
                sum[i] = MIN(sum[i], sum[j] + getDifficulty(j+1, i));
            }
        }
        cout << sum[size-1] << endl;
    }
    return 0;
}

int getDifficulty(int start, int end)
{
    // 모든 숫자가 같을 때
    int one = 1;
    for(int i=start; i<end; i++) {
        if(n[i] != n[i+1]) {
            one = 0;
            break;
        }
    }
    if(one) return 1;
    
    // 등차수열, 1단조 증감소
    int twoOrFive = 1;
    int d = n[start] - n[start+1];
    for(int i=start+1; i<end; i++) {
        if(n[i] - n[i+1] != d) {
            five = 0;
            break;
        }
    }
    if(twoOrFive) {
        if(d == 1 || d == -1) {
            return 2;
        }
        return 5;
    }
    
    // 번갈아 나타날때
    int odd, even, four = 1;
    if(start%2 == 1) {
        odd = n[start];
        even = n[start+1];
    } else {
        odd = n[start+1];
        even = n[start];
    }
    for(int i=start+2; i<=end; i++) {
        if(i%2 == 1) {
            if(odd != n[i]) {
                four = 0;
                break;
            }
        } else {
            if(even != n[i]) {
                four = 0;
                break;
            }
        }
    }
    if(four) return 4;
    
    return 10;
}
