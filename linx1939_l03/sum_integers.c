/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {

    // your code here
    int sum = 0;

    printf("Enter integers, one per line: \n");
    while(1){
        int num;
        int count = scanf("%d", &num);
        if(count == 1){
            sum += num;
        }
        else{
            break;
        }
    }
    return sum;
}