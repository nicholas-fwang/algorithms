#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > adj;
int N;
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int begin, end;
        scanf("%d%d", &begin, &end);
        adj.push_back(make_pair(end,begin));
    }
    sort(adj.begin(), adj.end());
    int size=0, lastEnd=0;
    for(int i=0; i<N; i++) {
        if(lastEnd <= adj[i].second) {
            lastEnd = adj[i].first;
            size++;
        }
    }
    printf("%d\n", size);
    return 0;
}