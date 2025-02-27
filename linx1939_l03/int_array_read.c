/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {

    // your code here
    int result;

    for(int i = 0; i < size; i++){
        printf("Enter value %d for the array of int:\n", i);
        printf("Value for index %d: ", i);
        while (1) {
            int num;
            int count = scanf("%d", &num);

            if (count == 1) {
                array[i] = num;
                break;
            } else {
                printf("Not a valid integer/n");
                while (getchar() != '\n'); 
            }
        }
    }


}