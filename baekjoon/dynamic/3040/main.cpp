#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int map[9];
vector<int> ret;
bool filled[9];
void solve(int n, int k, int sum);
int main()
{
    for(int i=0; i<9; i++) {
        scanf("%d", &map[i]);
    }
    solve(0,0,0);
    sort(ret.begin(), ret.begin()+7);
    for(int i=0; i<ret.size(); i++) {
        printf("%d\n", ret[i]);
    }
    return 0;
}

void solve(int n, int k, int sum)
{
    if(k == 7) {
        if(sum == 100) {
            for(int i=0; i<9; i++) {
                if(filled[i]) ret.push_back(map[i]);
            }
        }
        return ;
    }
    if(n == 9) return ;
    
    filled[n] = true;
    solve(n+1, k+1, sum+map[n]);
    filled[n]=false;
    solve(n+1, k, sum);
}