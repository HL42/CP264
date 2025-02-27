/*
 * your program signature
 */ 
 
#include "mystring.h"

/**
 *  add your comment
 */
int str_words(char *s) {
    // your code
    if(s == 0) return -1;
    
    char *p = s;
    int count = 0;

    while(*p){
        if(*p == 'A' && *p <= 'Z' || *p == 'a' && *p <= 'z'){
            count++;
        }
        p++;
    }
    return count;

}

/**
 *  add your comment
 */
int str_lower(char *s) {
    // your code
    if(s == 0) return -1;
    
    int count = 0;
    char *p = s;
    
    while(*p){
        if(*p == 'A' && *p <= 'Z'){
            *p = *p + 32;
            count ++;
        }
        p++;
    }

    return count;


}

/**
 *  add your comment
 */
void str_trim(char *s) {
    // your code
    char *p1 = s;
    char *p2 = s;
    char *ptr = s;
    while(*p1 == ' ' || *p1 == '\t'){
        p1++;
    }

    while(*p2) {
        p2++;
    }
    p2--;
    while(p2 > p1 && (*p2 == ' ' || *p2 == '\t')){
        p2--;
    }

    while(p1 <= p2){
        *ptr++ = *p1++;
    }
    *ptr = '\0';
}