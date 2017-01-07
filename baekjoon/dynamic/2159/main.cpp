#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const long long oo = 0x3f3f3f3f3f3f3f3f;
const int dir[5][2] = {{0,0},{0,1},{1,0},{-1,0},{0,-1}};

int N;
// n번째 사람에게 dir 방향으로 배달했을 때 n까지 최소 거리
long long cache[100001][5][5];
pair<int, int> map[100001];
long long solve(int n, int prev, int d);
long long cal(int prev, int cur, int d1, int d2);
bool inRange(int row, int col);
int main()
{
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    scanf("%d%d", &map[0].first, &map[0].second);
    for(int i=1; i<=N; i++) {
        scanf("%d%d", &map[i].first, &map[i].second);
    }
    long long ret = min(solve(1,0,0), min(solve(1,0,1), min(solve(1,0,2), min(solve(1,0,3), solve(1,0,4)))));
    printf("%lld\n", ret);
    return 0;
}

long long solve(int n, int prev, int d)
{
    if(n == N+1) return 0;
    
    long long& ret = cache[n][prev][d];
    if(ret != -1) return ret;
    ret = oo;
    
    long long cost = cal(n-1, n, prev, d);
    for(int i=0; i<5; i++) {
        if(cost >= 0) ret = min(ret, solve(n+1, d, i)+cost);
    }
    return ret;
}

long long cal(int prev, int cur, int d1, int d2)
{
    int nearRow = map[cur].first + dir[d2][0];
    int nearCol = map[cur].second + dir[d2][1];
    int prevRow = map[prev].first + dir[d1][0];
    int prevCol = map[prev].second + dir[d1][1];
    if(!inRange(nearRow, nearCol)) return -1;
    return abs(prevRow-nearRow)+abs(prevCol-nearCol);
}

bool inRange(int row, int col) {
    return row>=0 && row<=100000 && col>=0 && col<=100000;
}