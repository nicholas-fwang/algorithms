#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string w;
string a;

bool solve(int wi, int ai);

int main()
{
    int testCase;
    scanf("%d", &testCase);
    cin >> w;
    while(testCase--) {
        cin >> a;
        if(solve(0,0)) {
            printf("DA\n");
        } else {
            printf("NE\n");
        }
    }
    return 0;
}

bool solve(int wi, int ai)
{
    if(ai == a.size()-1 && wi == w.size()-1) {
        if(a[ai] == w[wi]) return true;
        else return false;
    }
    
    if(w[wi] == a[ai]) {
        return solve(wi+1, ai+1);
    } else if(w[wi] == '*') {
        for(int i=ai; i<a.size(); i++) {
            if(solve(wi+1, i)) {
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}