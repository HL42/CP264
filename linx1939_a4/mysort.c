/**
 * -------------------------------------
 * @file  mysort.c
 * file description
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier
 *
 * @version 2025-02-06
 *
 * -------------------------------------
 */
#include "mysort.h"

void swap(void **x, void **y){
     void *temp = *y;
     *y = *x;
     *x = temp;    
}


int cmp(void *x, void *y) {
   float a = *(float*)x;
   float b = *(float*)y; 
   return (a > b) - (a < b);
}




void select_sort(void *a[], int left, int right){
     for(int i = left; i < right; i++){
          int min = i;
          for(int j = i + 1; j < right; j++){
               if(cmp(a[min], a[j]) > 0){
                    min = j;
               }
          }
          swap(&a[i], &a[min]);
     }

}

void quick_sort(void *a[], int left, int right){
     if(left < right){
          int i = left + 1;
          int j = right;

          while (i <= j){
               while( i <= right && cmp(a[i], a[left]) <= 0) i++;
               while( j > left && cmp(a[j], a[left]) > 0) j--;

               if(i < j){
                    swap(&a[i], &a[j]);
               }

               swap(&a[left], &a[j]);

               quick_sort(a, left, j - 1);
               quick_sort(a, j + 1, right);
          
          }
     }

}

/**
 * Use either selection or quick sort algorithm to sort array of pointers such that their pointed values 
 * are in order defined by the given comparison function
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 * @param (*cmp) - pointer to a comparison function used to compaire pointers by their pointed values.
 */
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*) ){
     for(int i = left; i <= right; i++){
          int max = i;

          for(int j = i+1; j <= right; j++){
               if(cmp(a[max], a[j]) > 0){
                    max = j;
               }
          }

          if(max != i){
               swap(&a[i], &a[max]);
          }
     }

}