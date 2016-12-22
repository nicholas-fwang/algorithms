#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int N,W;
vector<pair<int, int> > map;
vector<string> name;
int cache[101][1001];
int solve(int n, int v);
void reconstruct(int n, int v, vector<string>& picked);
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        scanf("%d %d", &N, &W);
        memset(cache, -1, sizeof(cache));
        map = vector<pair<int, int> >(N+1);
        name = vector<string>(N+1);
        for(int i=0; i<N; i++) {
            int a,b;
            cin >> name[i];
            scanf("%d %d", &a, &b);
            map[i] = make_pair(a,b);
        }
        
        printf("%d ", solve(0,0));
        vector<string> picked;
        reconstruct(0,0,picked);
        printf("%d\n", picked.size());
        for(int i=0; i<picked.size(); i++) {
            cout << picked[i] << "\n";
        }
    }
    return 0;
}

int solve(int n, int v)
{
    if(n == N) return 0;
    
    int& ret = cache[n][v];
    if(ret != -1) return ret;
    
    ret = 0;
    
    ret = max(ret, solve(n+1, v));
    if(v+map[n].first <= W) ret = max(ret, solve(n+1, v+map[n].first)+map[n].second);
    
    return ret;
}

void reconstruct(int n, int v, vector<string>& picked) {
    if(n == N) return ;
    
    if(solve(n, v) == solve(n+1, v)) {
        reconstruct(n+1, v, picked);
    } else {
        picked.push_back(name[n]);
        reconstruct(n+1, v+map[n].first, picked);
    }
}