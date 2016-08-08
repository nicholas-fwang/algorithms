#include <iostream>
#include <string.h>

using namespace std;

int fibo[40][2];
int main()
{
    int testCase;
    cin >> testCase;
    fibo[0][0] = 1;
    fibo[1][0] = 0;
    
    fibo[0][1] = 0;
    fibo[1][1] = 1;
    
    while(testCase--) {
        int n;
        cin >> n;
        // counting 0 and conting 1 are each fibonacci
        for(int i=2; i<=n; i++) {
            fibo[i][0] = fibo[i-1][0] + fibo[i-2][0]; 
            fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
        }
        cout << fibo[n][0] << " " << fibo[n][1] << endl;
    }
    
    return 0;
}
