/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier.ca
 * 
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
    
    int sum = 0;

    while(1){
        printf("Enter three comma-separated integers: ");
        int num1, num2, num3;
        int count = scanf("%d,%d,%d", &num1, &num2, &num3);
        if(count == 3){
            sum = num1 + num2 + num3;
            break;
        }
        else{
            printf("The integers were not properly entered.\n");
            while(getchar() != '\n');
        }
    }
    


}