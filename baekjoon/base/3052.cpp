#include <iostream>
#include <cstdio>

using namespace std;
int arr[42];
int main()
{
    for(int i=0; i<10; i++) {
        int tmp;
        scanf("%d", &tmp);
        arr[tmp%42]++;
    }
    int ret = 0;
    for(int i=0; i<42; i++) {
        if(arr[i]>0) ret++;
    }
    printf("%d\n", ret);
    return 0;
}