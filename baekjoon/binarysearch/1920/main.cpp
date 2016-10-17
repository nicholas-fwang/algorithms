#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> child;

int findNumber(int src, int low, int high);

int main()
{
    int n,m;
    scanf("%d", &n);
    parent = vector<int>(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &parent[i]);
    }
    scanf("%d", &m);
    child = vector<int>(m);
    for(int i=0; i<m; i++) {
        scanf("%d", &child[i]);
    }
    sort(parent.begin(), parent.end());
    for(int i=0; i<m; i++) {
        printf("%d\n", binary_search(parent.begin(), parent.end(), child[i]));
    }
    return 0;
}
