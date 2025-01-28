/**
 * -------------------------------------
 * @file  fibonacci.c
 * file description
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier
 *
 * @version 2025-01-22
 *
 * -------------------------------------
 */
#include "fibonacci.h"

int recursive_fibonacci(int n) {
    // your implementation
    if(n < 0){
        return -1;
    }

    if(n == 0){
        return 0;
    } else if(n == 1 || n == 2 ){
        return 1;
    } else{
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
    }

    
}

int iterative_fibonacci(int n)
{
    // your implementation
    if(n < 0){
        return -1;
    }

    if(n == 0){
        return 0;
    } else if(n == 1 || n == 2 ){
        return 1;
    } else{
        int a = 1 , b = 1, c;
        for (int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
    
}

int dpbu_fibonacci(int *f, int n) {
    // your implementation
    if(n < 0){
        return -1;
    }

    if(n == 0){
        f[0] = 0;
        return 0;
    }
    if(n == 1 || n == 2){
        return 1;
    }
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];

    
}

int dptd_fibonacci(int *f, int n) {
    // your implementation
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 0;
    }
    if(n == 1 || n == 2){
        f[1] = 1;
        return 1;
    }

    return f[n] = dptd_fibonacci(f, n-1) + dptd_fibonacci(f, n-2);

}
