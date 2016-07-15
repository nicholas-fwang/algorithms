/**
*   author : fisache
*   link : https://www.algospot.com/judge/problem/read/PICNIC
*/
#include <iostream>
#include <string.h>

using namespace std;

int areFriends[10][10];
int taken[10];
int n;

/** recursive function for finding pairs */
int countPair(void);

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        memset(areFriends, 0, sizeof(areFriends));
        memset(taken, 0, sizeof(taken));
        int m;
        cin >> n;
        cin >> m;
        for(int pair = 0; pair < m; pair++) {
            int first, second;
            cin >> first;
            cin >> second;
            /** main concept is to match the pair with array[smaller][bigger] */
            if(first < second) areFriends[first][second] = 1;
            else areFriends[second][first] = 1;
        }
        cout << countPair() << endl;
    }
    return 0;
}

int countPair(void)
{
    int isNotPaired = -1;
    for(int i=0; i < n; i++) {
        if(taken[i] == 0) {
            isNotPaired = i;
            break;
        }
    }
    
    /* base step*/
    if(isNotPaired == -1) return 1;
    int ret = 0;
    
    /** For avoding overlapped counting, only operates calculation in case that paired is bigger than isNotPaired*/
    for(int paired = isNotPaired+1; paired < n; paired++) {
        if(areFriends[isNotPaired][paired] && !taken[paired]) {
            taken[isNotPaired] = taken[paired] = 1;
            ret += countPair();
            taken[isNotPaired] = taken[paired] = 0;
        }
    }
    /** if not match areFriends, return 0 */
    return ret;
}