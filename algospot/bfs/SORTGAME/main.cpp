#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 1~8개를 가지고 수열의 갯수마다 그래프를 다 가지고 있는다
vector<map<vector<int>, int> > toSort;

void makeGraph(int n);
int bfs(const vector<int>& perm);
int main()
{
    toSort = vector<map<vector<int>, int> >(9);
    // 각 수열 길이마다 그래프를 만든다
    for(int i=1; i<=8; i++) {
        makeGraph(i);
    }
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int n;
        scanf("%d", &n);
        vector<int> perm = vector<int>(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &perm[i]);
        }
        int ret = bfs(perm);
        printf("%d\n", ret);
    }
    
    return 0;
}

void makeGraph(int n)
{
    vector<int> perm = vector<int>(n);
    for(int i=0; i<n; i++) {
        perm[i] = i;
    }
    queue<vector<int> > q;
    q.push(perm);
    toSort[n][perm] = 0;
    while(!q.empty()) {
        vector<int> here = q.front();
        q.pop();
        int cost = toSort[n][here];
        // 모든 경우를 다 뒤집는다.
        for(int i=0; i<n; i++) {
            for(int j=i+2; j<=n; j++) {
                reverse(here.begin()+i, here.begin()+j);
                if(toSort[n].count(here) == 0) {
                    toSort[n][here] = cost+1;
                    q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
    
}

int bfs(const vector<int>& perm)
{
    int n = perm.size();
    vector<int> fixed = vector<int>(n);
    
    for(int i=0; i<n; i++) {
        int smaller = 0;
        for(int j=0; j<n; j++) {
            // 나보다 작은애가 몇갠지 새본다.
            if(perm[i] > perm[j]) ++smaller;
        }
        fixed[i] = smaller;
    }
    return toSort[n][fixed];
}