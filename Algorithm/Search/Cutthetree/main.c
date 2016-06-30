#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int data[100001];
//int flag[100001];
int sumTree(int **e, int index, int size)
{
    int i;
    int sum = data[index];
    int dir=0;
    for(i=0; i<size; i++) {
        //if((e[index][i] == 1 || e[i][index] == 1) && flag[i] == 0) {
        if(e[index][i] == 1 || e[i][index] == 1) {
//            flag[i] = -1;
            if(e[index][i] == 1) {
                dir = 1;
                e[index][i] = 0;
            } else {
                dir = 2;
                e[i][index] = 0;
            }
            
            sum += sumTree(e, i, size);
            
            if(dir == 1) e[index][i] = 1;
            else e[i][index] = 1;
        }
    }
    return sum;
}

int main()
{
    int verticsNumber;
    int i, j, z;
    int **e;
    long int min = 0xffffffff;
    
    scanf("%d", &verticsNumber);
    for(i=0; i<verticsNumber; i++) {
        scanf("%d", &data[i]);
    }
    e = (int **) malloc(sizeof(int *)*verticsNumber);
    for(i=0; i<verticsNumber; i++) {
        e[i] = (int *) malloc(sizeof(int)*verticsNumber);
    }
    for(i=0; i<verticsNumber; i++) {
        for(j=0; j<verticsNumber; j++) {
            e[i][j] = 0;
        }
    }
    
    for(i=0; i<verticsNumber-1; i++) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        e[c1-1][c2-1] = 1;
    }
    
    for(i=0; i<verticsNumber; i++) {
        for(j=0; j<verticsNumber; j++) {
            if(e[i][j] == 1) {
//                for(z=0; z<verticsNumber; z++) {
//                    flag[z] = 0;
//                }
//                flag[i] = -1;
//                flag[j] = -1;
                e[i][j] = 0;
                int diff = abs(sumTree(e, i, verticsNumber) - sumTree(e, j, verticsNumber));
                if(diff < min) {
                    min = diff;
                }
                e[i][j] = 1;
            }
        }
    }
    
    printf("%ld\n", min);
    
    for(i=0; i<verticsNumber; i++) {
        free(e[i]);
    }
    free(e);
    return 0;
}