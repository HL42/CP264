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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#include "mysort.h"

GRADE grade(float score){
   GRADE r = {"F"}; 
   // your code
   int p = (int) round(score);
   char g[14][5] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "D-", "F"};
   int b[] = {100, 90, 85, 80, 77, 73, 70, 67, 63, 60, 57, 53, 50, 0};
   int i=0, n = sizeof(b)/sizeof(float);
   for (i=0; i<n; i++) {
        if (score >= b[i+1]) break;
    }
    
    strcpy(r.letter_grade, g[i]); 
    
    
    return r;   
}


int import_data(FILE *fp, RECORD *dataset) {
    // your code
    if(fp == NULL || dataset == NULL) return 0;
    
    char delimiters[] = " ,\n\r";
    char line[100];
    int count = 0;

    while(fgets(line, sizeof(line), fp) != NULL){
        if(line[0] == '\0' || line[0] == '\n')
            continue;
        
        char *token = strtok(line, delimiters);

        if(token == NULL){
            continue;
        }

        strncpy(dataset[count].name, token, sizeof(dataset[count].name)-1);

        dataset[count].name[sizeof(dataset[count].name)-1] = '\0';

        token = strtok(NULL, delimiters);

        if(token == NULL)
            continue;
        dataset[count].score = atof(token);
        count++;

    }


    return count;

}

STATS process_data(RECORD *dataset, int count) {    
    // your code
    STATS stats = {0};
    stats.count = count;

    if(count <= 0){
        stats.mean = stats.stddev = stats.median = 0.0;
        return stats;
    }

    float total = 0.0;
    for(int i = 0; i < count; i++){
        total += dataset[i].score;
    }

    stats.mean = total / count;

    float std = 0.0;
    for(int i = 0; i < count; i++){
        float diff = dataset[i].score - stats.mean;

        std += diff * diff;

    }

    stats.stddev = sqrt(std / count);

    float *score_ptrs[count];

    if(count == 0){
        stats.median = 0.0;
        return stats;
    }

    for(int i = 0; i < count; i++){
        score_ptrs[i] = &dataset[i].score;

    }

    quick_sort((void**)score_ptrs, 0, count - 1);


    if(count % 2 == 1){
        stats.median = *score_ptrs[count / 2];

    } else{
        stats.median = (*score_ptrs[count / 2] + *score_ptrs[count / 2 - 1])/ 2.0;
    }

    return stats;


}

int report_data(FILE *fp, RECORD *dataset, STATS stats) {
    // your code
    int n = stats.count;
    if(fp == NULL || dataset == NULL || n < 1){
        return 0;

    }


    fprintf(fp, "stats:\n");
    fprintf(fp, "count:%d\n", stats.count);
    fprintf(fp, "mean:%.2f\n", stats.mean);
    fprintf(fp, "stddev:%.2f\n", stats.stddev);
    fprintf(fp, "median:%.2f\n\n", stats.median);

    fprintf(fp, "%s%s%s\n", "name:", "score:", "grade:");

    RECORD *p[n];
    for (int i = 0; i < stats.count; i++) {
        p[i] = &dataset[i];
    }

    my_sort((void **)p, 0, stats.count - 1, cmp2);

    for (int i = 0; i < stats.count; i++) {
        GRADE g = grade(dataset[i].score);
        fprintf(fp, "%s:%.1f,%s\n", p[i]->name, p[i]->score,grade(p[i]->score).letter_grade);
    }

    return 1;

}
int cmp2(void *x, void *y) {
    float a = ((RECORD*)x)->score;
    float b = ((RECORD*)y)->score;
    if (a > b) return -1;   
    else if (a < b) return 1;
    else return 0;
}