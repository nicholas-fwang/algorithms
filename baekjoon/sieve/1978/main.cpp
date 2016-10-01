#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<bool> sieve;

int main()
{
    sieve = vector<bool>(1001, true);
    sieve[0] = false;
    sieve[1] = false;
    for(int i=2; (i*i)<=1000; i++) {
        for(int j=i*i; j<=1000; j+=i) {
            if(sieve[j]) sieve[j] = false;
        }
    }
    int n, ret=0;
    scanf("%d", &n);
    for(int i=0;i<n; i++) {
        int v;
        scanf("%d", &v);
        if(sieve[v]) ret++;
    }
    printf("%d\n", ret);
    return 0;
}