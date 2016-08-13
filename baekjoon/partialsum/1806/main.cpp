#include <iostream>

#define MIN(a,b) a>b ? b:a

using namespace std;

const int oo = 0x3f3f3f3f;

int p[100001];
int psum[100001];
int main()
{
    int n, s;
    cin >> n >> s;
    for(int i=1; i<=n; i++) {
        int tmp;
        cin >> tmp;
        p[i] = tmp;
    }
    
    psum[0] = 0;
    psum[1] = p[1];
    // p[1]부터 p[i]까지의 부분합을 구한다
    for(int i=2; i<=n; i++) {
        psum[i] = psum[i-1] + p[i];
    }
    
    int len = oo;
    for(int i=n; i>=1; i--) {
        for(int j=i-1; j>=0; j--) {
            // 이전에 구한 최소길이보다 부분합의 길이가 같거나 길경우는 무시한다
            if(i-j >= len) break;
            if(psum[i] - psum[j] >= s) {
                // s보다 크거나 같은 부분합의 최소값을 구한다
                len = MIN(len, i-j);
            }
        }
    }
  
    // s보다 크거나 같은 부분합을 구하지 못했다
    if(len == oo) cout << "0" << endl;
    else cout << len << endl;

    return 0;
}