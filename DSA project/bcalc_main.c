#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bcalc.h"
#include "list.h"
#include "stack.h"

int main()
{
          list L1;
          List L2;
          Node *ptr, *res;
          node *rev;
          int decimal = 0, i = 0, count = 0, total_count = 0, error = 0;
          char ch = 'a';
          char str[100];
          while (i != 9)
          {
                    scanf("%s", str);
                    // switch (ch)
                    // {
                    // case 'q':
                    //           break;
                    // default:
                    if (str[i] == 'q')
                    {
                              return 0;
                    }
                    else
                    {
                              while (str[i] != '\0')
                              {
                                        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^')
                                        {
                                                  count++;
                                        }
                                        total_count++;
                                        i++;
                              }
                              error = find_error(str, total_count);
                              if (error == 1)
                              {
                                        printf("Invalid Input\n");
                              }
                              else
                              {

                                        ptr = init(str, count, total_count);

                                        rev = evaluation(str, count, total_count, ptr);

                                        display_num(rev);
                                        printf("\n");
                                        printf("\n");
                              }
                              error = 0;
                    }
          }
          return 0;
}