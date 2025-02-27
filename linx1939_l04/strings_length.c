/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {

    // your code here
    if(data == NULL){
        return;
    }

    for(int i = 0; i < data->lines; i++){
        size_t curr_length = strlen(data->strings[i]);

        if(curr_length < length){
            fprintf(fp_short, "%s\n", data->strings[i]);
        } else{
            fprintf(fp_long, "%s\n", data->strings[i]);
        }
        
    }

}