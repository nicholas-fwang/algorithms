#include <iostream>
#include <string.h>
#include <limits.h>

#define MIN(a,b) a>b ? b : a

const int INFTY = INT_MAX;

using namespace std;

int getLeastCost(int row, int rgb);

int house[1000][3];
int cache[1000][3];
int n;
int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            int tmp;
            cin >> tmp;        
            house[i][j] = tmp;
        }
    }
    int ret = INFTY;
    for(int i=0; i<3; i++) {
        ret = MIN(ret, getLeastCost(0, i));
    }
    cout << ret << endl;
    return 0;
}

// recursive function
int getLeastCost(int row, int rgb)
{
    // base step
    if(row == n-1) {
        return house[row][rgb];
    }
    
    // memoization
    int& ret = cache[row][rgb];
    if(ret != -1) {
        return ret;
    }
    ret = INFTY;
    int cost = house[row][rgb];
    for(int i=0; i<3; i++) {
        // except case of same color
        if(i != rgb) {
            ret = MIN(ret, getLeastCost(row+1, i)+cost);    
        }
    }
    return ret;
}