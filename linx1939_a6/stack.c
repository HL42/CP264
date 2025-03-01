/**
 * -------------------------------------
 * @file  stack.c
 * file description
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier
 *
 * @version 2025-02-28
 *
 * -------------------------------------
 */

#include "stack.h"
#include <stdio.h>

void push(STACK *sp, NODE *np)
{
    if (!sp || !np)
        return;

    np->next = sp->top;
    sp->top = np;
    sp->length++;
}

NODE *pop(STACK *sp)
{
    if (sp == NULL || sp->top == NULL)
    {
        return NULL;
    }

    NODE *temp = sp->top;
    sp->top = sp->top->next;
    temp->next = NULL;
    sp->length--;

    return temp;
}

void clean_stack(STACK *sp)
{
    clean(&(sp->top));
    sp->top = NULL;
    sp->length = 0;
}