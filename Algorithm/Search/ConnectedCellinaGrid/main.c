#include <stdio.h>
#include <stdlib.h>

int recursionConnect(int** c, int i, int j, int m, int n)
{
    int connect = 0;
    // base case if don't have adjacent, return 0
    if(c[i-1][j-1] != 1 && c[i-1][j] != 1 && c[i-1][j+1] != 1 &&
      c[i][j-1] != 1 && c[i][j+1] != 1 && c[i+1][j-1] != 1 &&
      c[i+1][j] != 1 && c[i+1][j+1] != 1) {
        return 0;
    } else {
        int z, v;
        // if have adjacent 1, recursive step
        for(z=-1; z<=1; z++) {
            for(v=-1; v<=1; v++) {
                if(z==0 && v==0) v++;
                if(c[i+z][j+v] == 1) {
                    c[i+z][j+v] = -1;
                    connect += recursionConnect(c, i+z, j+v, m, n) +1;
                }
            }
        }
        return connect;
    }
}

int main()
{
    int n, m;
    int i, j, max=0, connect;
    int **c;
    c = (int **) malloc(sizeof(int *)*12);
    for(i=0; i<12; i++) {
        c[i] = (int *) malloc(sizeof(int)*12);
    }
    
    scanf("%d", &m);
    scanf("%d", &n);
    for(i=0; i<=m+1; i++) {
        for(j=0; j<=n+1; j++) {
            c[i][j] = 0;
        }
    }
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    
    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            if(c[i][j] == 1) {
                c[i][j] = -1;
                connect = recursionConnect(c, i, j, m, n) + 1;
                if(connect > max) {
                    max = connect;
                }
            }
        }
    }
    printf("%d\n", max);
    for(i=0; i<12; i++) {
        free(c[i]);
    }
    free(c);
    return 0;
}