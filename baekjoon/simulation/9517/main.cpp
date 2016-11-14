#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
const int timeover = 210;

int main()
{
    int first;
    int n;
    scanf("%d %d", &first, &n);
    first--;
    int time = 0;
    for(int i=0; i<n; i++) {
        int a;
        char b;
        scanf("%d %c", &a, &b);
        bool boom = false;
        time+=a;
        if(time >= timeover) {
            printf("%d\n", first+1);
            return 0;
        }
        if(b == 'T') first = (first+1==8 ? 0 : first+1);
    }
    
    return 0;
}