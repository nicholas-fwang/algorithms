#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool sieve[10001];
vector<vector<int> > adj;

int bfs(int start, int end);

int main()
{
    for(int i=2; i<=9999; i++) {
        sieve[i] = true;
    }
    // 에라토스테네스의 체
    sieve[0] = sieve[1] = false;
    for(int i=2; i*i<=9999; i++) {
        for(int j=i*i; j<=9999; j+=i) {
            if(sieve[j]) sieve[j] = false;
        }
    }
    adj = vector<vector<int> >(10001);
    for(int i=1000; i<=9999; i++) {
        // i가 소수이면
        if(sieve[i]) {
            // 1의자리부터 1000의자리까지 하나씩 바꿔가며 소수인지 확인하고 리스트에 추가한다.
            for(int j=1; j<=1000; j*=10) {
                int m = i-(i%(j*10))+(i%j);
                for(int k=0; k<=9*j; k+=j) {
                    if(sieve[m+k] && i != m+k && m+k>1000) {
                        adj[i].push_back(m+k);
                    }
                }
            }
        }
    }
    
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int a,b;
        scanf("%d %d", &a, &b);
        if(a==b) {
            printf("0\n");
            continue;
        }
        int ret = bfs(a,b);
        if(ret == -1) printf("Impossible\n");
        else printf("%d\n", ret);
    }
    
    return 0;
}

int bfs(int start, int end)
{
    // 너비 우선 탐색 최단길이 계산
    vector<int> distance = vector<int>(adj.size(), -1);
    queue<int> q;
    distance[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i];
            if(distance[there] == -1) {
                q.push(there);
                distance[there] = distance[here]+1;
                if(there == end) return distance[there];
            }
        }
    }
    return -1;
}