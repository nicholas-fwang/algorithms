#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

struct Node {
    int number;
    int len;
    vector<int> children;
};

int solve(int n);
int getMax(int n);

Node tree[10001];
int cache[10001];

int main()
{
    int n;
    scanf("%d", &n);
    memset(cache, -1, sizeof(cache));
    tree[1].len = 0;
    
    for(int i=0; i<n-1; i++) {
        int parent, child, len;
        scanf("%d %d %d", &parent, &child, &len);
        tree[child].len = len;
        tree[parent].children.push_back(child);
    }
    int ret = solve(n);
    printf("%d\n", ret);
    
    return 0;
}

int solve(int n)
{
    int ret = 0;
    /// 전체 노드를 순회하면서 하위노드를 1개 이상가진 애(리프가 아니다)를 가지고 지름의 길이를 구한다. 그 중 최대가 되는 값을 반환한다.
    for(int i=1; i<=n; i++) {
        if(tree[i].children.size() >= 1) {
            int max1 = 0, max2 = 0;
            for(int j=0; j<tree[i].children.size(); j++) {
                int tmp = getMax(tree[i].children[j]);
                if(max1 < tmp || max2 < tmp) {
                    if(max1 > max2) {
                        max2 = tmp;
                    } else {
                        max1 = tmp;
                    }
                }
            }
            ret = max(ret, max1+max2);
        }
    }
    return ret;
}

// n번째 노드의 하위트리로 만들 수 있는 최대값을 구한다
// cache를 사용해서 n번째 하위트리로 만들 수 있는 값이 구해져있으면 그걸쓴다
int getMax(int n)
{
    if(tree[n].children.size() == 0) {
        return tree[n].len;    
    }
    
    int& ret = cache[n];
    if(ret != -1) {
        return ret;
    }
    
    for(int i=0; i<tree[n].children.size(); i++) {
        ret = max(ret, getMax(tree[n].children[i]) + tree[n].len);
    }
    return ret;
}