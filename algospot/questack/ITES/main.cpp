#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        int k, n;
        int sum = 0;
        int ret = 0;
        queue<int> range;
        cin >> k >> n;
        int signal;
        unsigned long next = 1983;
        for(int i=1; i<=n; i++) { 
            // i == 1일 때 a0은 1983 초기값이다
            if(i > 1) {
                next = (next*214013 + 2531011) % (1L << 32);    
            }
            signal = next % 10000 + 1;
            sum += signal;
            range.push(signal);
            
            while(sum > k) {
                sum -= range.front();
                range.pop();
            }
            
            // 부분합이 k와 같을 때
            if(sum == k) {
                ret++;
            }
        }
        cout << ret << endl;
    }
    return 0;
}