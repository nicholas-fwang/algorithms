#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int adj[1001][1001];
int N;

int ret[10000001];
int retSize = 0;

void eulerCircuit(int here)
{
    for(int i=0; i<N; i++) {
        if(adj[i][here] > 0) {
            adj[i][here]--;
            adj[here][i]--;
            eulerCircuit(i);
        }
    }
    ret[retSize++] = here;
}

int main()
{
    scanf("%d", &N);
    int edges = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int tmp;
            scanf("%d", &tmp);
            adj[i][j] = tmp;
            edges += adj[i][j];
        }
        if((edges%2) == 1) {
            printf("-1\n");
            return 0;
        }
    }
    eulerCircuit(0);
    for(int i=0; i<retSize; i++) {
        printf("%d ", ret[i]+1);
    }

    return 0;
}