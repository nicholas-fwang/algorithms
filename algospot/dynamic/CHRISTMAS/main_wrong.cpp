#include <iostream>
#include <vector>
#include <string.h>

#define MAX(a,b) a>b ? a:b

const int MOD = 20091101;

using namespace std;

int box[100001];
int psmod[100001];
long long oneCount[100001];

int dp[100001];
int pre[100001];
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
        
        long long cnt = 0;
        memset(oneCount, 0, sizeof(oneCount));
        for(int i=1; i<=n; i++) {
            // i까지의 합을 k로 나눈 나머지가 oneCount의 인덱스가 된다
            oneCount[psmod[i]]++;
        }
        for(int i=0; i<k; i++) {
            if(oneCount[i] >= 2) {
                // onCount[i] C 2 조합, 2개 이상의 oneCount에서 순서 상관없이 2개를 뽑는 경우의 수
                cnt = (cnt +((oneCount[i]*(oneCount[i]-1))/2)) % MOD;
            }
        }
        
        memset(pre, -1, sizeof(pre));
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            dp[i] = dp[i-1];
            // 나머지가 같은애가 전에 있었으면 그 인덱스를 가져온다
            int loc = pre[psmod[i]];
            if(loc != -1) {
                // 나머지가 같다는 것은 이전 상자에서부터 현재 상자까지 한번에 가질 수 있다는 뜻이다
                dp[i] = MAX(dp[i], dp[loc]+1);
            }
            // 현재 인덱스를 저장한다
            pre[psmod[i]] = i;
        }
        
        cout << cnt << " " << dp[n] << endl;
        
    }
    return 0;
}
