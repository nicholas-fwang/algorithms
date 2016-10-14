#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int oo = 0x3f3f3f3f;

int N;
int map[10001];
int rights[10001];
int cache[10001][10];
int how[10000][10];
int to[10000][10];
int cost[10000][10];

int solve(int n, int rotate);
void print(int index, int turn) {
    if (index == N) {
        return;
    }
    if (cost[index][turn] == 0) {
        print(index+1, turn);
    } else {
        printf("%d ",index+1);
        if (how[index][turn] == 2) {
            printf("-");
        }
        printf("%d\n",cost[index][turn]);
        print(index+1, to[index][turn]);
    }
}

int main()
{
    scanf("%d", &N);
    memset(cache, -1, sizeof(cache));
    string s;
    cin >> s;
    for(int i=0; i<N; i++) {
        map[i] = s[i]-'0';
    }
    string r;
    cin >> r;
    for(int i=0; i<N; i++) {
        rights[i] = r[i]-'0';
    }
    int ret = solve(0, 0);
    printf("%d\n", ret);
    print(0, 0);
    return 0;
}

int solve(int n, int rotate)
{
    if(n == N) return 0;
    
    int& ret = cache[n][rotate];
    if(ret != -1) return ret;
    ret = oo;
    int pos = (map[n]+rotate)%10;
    int cost_l = (rights[n] + 10 - pos) %10;
    int left = solve(n+1, (rotate+cost_l)%10) + cost_l;
    int cost_r = (pos + 10 - rights[n]) % 10;
    int right = solve(n+1, rotate) + cost_r;
    if(left < right) {
        ret = left;
        how[n][rotate] = 1;
        to[n][rotate] = (rotate+cost_l) % 10;
        cost[n][rotate] = cost_l;
    } else {
        ret = right;
        how[n][rotate] = 2;
        to[n][rotate] = rotate;
        cost[n][rotate] = cost_r;
    }
    
    return ret;
}