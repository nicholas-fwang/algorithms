/** 
* author : fisache
* link : https://www.algospot.com/judge/problem/read/CLOCKSYNC
**/

#include <iostream>

#define MIN(a,b) a>b ? b : a
#define INT 9999

using namespace std;

/** the number of clock linked in each switch*/
int switchCount[10] = {3,4,4,5,5,4,3,5,5,5};
/** the clock index of clock linked in each switch*/
int switchGroup[10][5] = {
    {0,1,2},
    {3,7,9,11},
    {4,10,14,15},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15},
    {3,14,15},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};
/** current clock*/
int clockState[16];

bool areTwelve(void);
void push(int sw);
int pushSwitch(int sw);

int main()
{
    int testCase;
    cin >> testCase;
    while(testCase--) {
        for(int i=0; i<16; i++) {
            cin >> clockState[i];
        }
        int result = pushSwitch(0);
        if(result == INT) cout << "-1" << endl;
        else cout << result << endl;
    }
    return 0;
}

/** check all clock indicate 12*/
bool areTwelve()
{
    for(int i=0; i<16; i++) {
        if(clockState[i] != 12) {
            return false;
        }
    }
    return true;
}

/** when invoked, the clocks linked in sw move by 3*/
void push(int sw) {
    for(int i=0; i<switchCount[sw]; i++) {
        int clockNumber = switchGroup[sw][i];
        clockState[clockNumber] += 3;
        if(clockState[clockNumber] == 15) {
            clockState[clockNumber] = 3;
        }
    }
}

int pushSwitch(int sw)
{
    /** base step*/
    if(sw == 10) {
        return areTwelve() ? 0 : INT;
    }
    
    int ret = INT;
    for(int i=0; i<4; i++) {
        ret = MIN(ret, pushSwitch(sw+1)+i);
        push(sw);
    }
    return ret;
}