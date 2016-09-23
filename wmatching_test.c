#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wmatching.h"

#include "old/mwm.h"

#define N 64
#define TEST 10000
#define MAX_ 1000000
int main()
{
    int **a;
    int n = N;
    int mateA[N];
    int mateB[N];
    int i, j, t;
    int counter = 0;
    int flag = 0;
    int wA, wB;
    srand(time(NULL));
    a = (int **) malloc(n * sizeof(int *));
    for (i = 0;i < n;++ i) 
    {
        a[i] = (int *) malloc(n * sizeof(int));
    }
    // random
    for (t = 0;t < TEST;++ t){
        for (i = 0;i < n;++ i)
        {
            for (j = 0;j < n;++ j)
            {
                a[i][j] = rand() % MAX_;
            }
        }

        wmatch_sbp_int(n, a, mateA);
        MWM(n, a, mateB);

        flag = 0;
        for (i = 0;i < n;++ i) /* printf("%d\t", mate[i]);*/
            if (mateA[i] != mateB[i])
            {
                flag = 1;
                break;
            }
        if (flag == 1)
        {
            wA = 0;
            wB = 0;
            for (i = 0;i < n;++ i) 
            {
                wA += (mateA[i] == -1)? 0:a[i][mateA[i]];
                wB += (mateB[i] == -1)? 0:a[i][mateB[i]];
            }
            if (wA != wB) ++ counter;
        }
        if (t > 0 && (t % 40 == 0)) printf("counter = %d\n", counter);
    }
    
    printf("%d/%d inconsistent\n", counter, TEST);
    for (i  = 0;i < n;++ i) free(a[i]);
    free(a);
    return 0;
}