#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n[100000];
int main()
{
    int testCase;
    scanf("%d", &testCase);
    while(testCase--) {
        int N,Q;
        scanf("%d %d", &N, &Q);
        for(int i=0; i<N; i++) {
            int tmp;
            scanf("%d", &tmp);
            n[i] = tmp;
        }
        while(Q--) {
            priority_queue<int, vector<int>, less<int> > maxHeap;
            priority_queue<int, vector<int>, greater<int> > minHeap;
            int a,b;
            scanf("%d %d", &a, &b);
            for(int i=a; i<=b; i++) {
                maxHeap.push(n[i]);
                minHeap.push(n[i]);
            }
            printf("%d\n", maxHeap.top()-minHeap.top());
        }
    }
    return 0;
}