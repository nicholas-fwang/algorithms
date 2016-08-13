#include <iostream>
#include <vector>
#include <string.h>

#define MAX(a,b) a>b ? a:b

using namespace std;

int box[100001];
int psmod[100001];
int oneCount[100000];

int cache[100001];
int solve(int left);
int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        int n, k;
        cin >> n >> k;   
        for(int i=1; i<=n; i++) {
            int tmp;
            cin >> tmp;
            box[i] = tmp;
        }
        box[0] = 0;
        psmod[0] = 0;
        psmod[1] = box[1]%k;
        for(int i=2; i<=n; i++) {
            psmod[i] = (psmod[i-1] + box[i])%k;
        }
        
        int cnt = 0;
        memset(oneCount, 0, sizeof(oneCount));
        for(int i=1; i<=n; i++) {
            oneCount[psmod[i]]++;
        }
        for(int i=0; i<k; i++) {
            if(oneCount[i] >= 2) {
                cnt += (oneCount[i]*(oneCount[i]-1))/2;
            }
        }
        cnt %= 20091101;
        
        memset(cache, -1, sizeof(cache));
        int result = solve(n);
        
        cout << cnt << " " << result << endl;
        
    }
    return 0;
}

int solve(int left)
{
    if(left == 0) {
        return 0;
    }
    
    int& ret = cache[left];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    for(int i=left-1; i>=0; i--) {
        int tmp = psmod[left];
        // 나머지가 같다 i 초과부터 left까지 상자를 선택한다
        if(psmod[i] == tmp) {
            ret = MAX(ret, solve(i)+1);
        }
        // i 초과부터 left까지 상자를 선택하지 않는다
        ret = MAX(ret, solve(i));
    }
    return ret;
}