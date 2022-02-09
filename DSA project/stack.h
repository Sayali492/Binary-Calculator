typedef struct stack
{
          int size;
          int top;
          int *A;

} stack;

void init_stack(stack *S, int s);
int is_stack_empty(stack S);
int is_stack_full(stack S);
void push(stack *S, int d);
int pop(stack *S);
int peak(stack S);