#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    priority_queue<int> pq;
    for(int i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        pq.push(-tmp);
    }
    while(!pq.empty()) {
        printf("%d\n", -pq.top());
        pq.pop();
    }
    return 0;
}