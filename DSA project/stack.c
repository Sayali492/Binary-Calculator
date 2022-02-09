#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bcalc.h"
#include "list.h"
#include "stack.h"



void init_stack(stack *S, int s)
{
          S->size = s;
          S->top = -1;
          S->A = (int *)malloc(sizeof(int) * s);
          return;
}

int is_stack_empty(stack S)
{
          if (S.top == -1)
                    return 1;
          else
                    return 0;
}
int is_stack_full(stack S)
{
          if (S.top == S.size - 1)
                    return 1;
          else
                    return 0;
}
void push(stack *S, int d)
{
          if (S->top == -1)
          {
                    S->top++;
                    S->A[S->top] = d;
                    return;
          }
          else if (is_stack_full(*S))
                    return;
          else
          {
                    S->top++;
                    S->A[S->top] = d;
                    return;
          }
}

int pop(stack *S)

{
          long int num;
          num = INT_MIN;
          if (is_stack_empty(*S))
                    return num;
          else
          {

                    int x;
                    x = S->A[S->top];
                    S->top--;
                    return x;
          }
}

int peak(stack S)
{
          long int num;
          num = INT_MIN;
          if (is_stack_empty(S))
                    return num;
          else
          {
                    int x;
                    x = S.A[S.top];

                    return x;
          }
}
