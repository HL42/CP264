/**
 * -------------------------------------
 * @file  polynomial.c
 * file description
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier
 *
 * @version 2025-01-22
 *
 * -------------------------------------
 */

#include <stdio.h>
#include "polynomial.h"
#define EPSILON 1e-6
#define MAXCOUNT 100

float horner(float *p, int n, float x)
{
    // your implementation
    float result = 0.0;

    for(int i = 0; i < n; i++){
        result = result * x + p[i];
    }

    return result;
}

void derivative(float *p, float *d, int n)
{
    // your implementation
    for(int i = 0; i < n; i++){
        d[i] = (n - 1 - i) * p[i];
    } 

}

// add auxilliary function float myfabs(floatx) to return the absolute value x
float myfabs(float x){
    return (x < 0) ? -x : x;
}

float newton(float *p, int n, float x0)
{
    // your implementation, may use myfabs() to simply the code. 
    float fx, d_fx;
    int count = 0;

    while(count < MAXCOUNT){
        fx = horner(p, n, x0);
        float d_c[n -1];
        derivative(p, d_c, n);

        d_fx = horner(d_c, n - 1, x0); //p'(x)

        if(myfabs(d_fx) < EPSILON){
            break;
        }

        x0 = x0 - fx / d_fx;
        count++;

        if(myfabs(fx) < EPSILON){
            break;
        }

    }

    return x0;

}
