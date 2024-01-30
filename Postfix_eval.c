#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};
struct Stack* createstack(unsigned capacity)
{
    struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int *)malloc(stack->capacity*sizeof(int));
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top==-1;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{ 
    if(!isEmpty(stack))
        return stack->array[stack->top--];
        return -1;
}
void push(struct Stack* stack,char op)
{
    stack->array[++stack->top]=op;
}
int evaluatepostfix(char* exp)
{
    struct Stack* stack=createstack(strlen(exp));
    int i;
    if(!stack)
    return -1;
    for(i=0;exp[i];++i)
    {
        if(isdigit(exp[i]))
        {
            push(stack,exp[i]-'0');
        }
        else
        {
            int v1=pop(stack);
            int v2=pop(stack);
            switch(exp[i])
            {
                case '+':
                push(stack,v2+v1);
                break;
                
                case '-':
                push(stack,v2-v1);
                break;
                
                case '*':
                push(stack,v2*v1);
                break;
                
                case '/':
                push(stack,v2/v1);
                break;
            }
        }
    }
    return pop(stack);
}
int main()
{
    char exp[100];
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    printf("Postfix Expression: %s\n",exp);
    printf("value of postfix: %d\n",evaluatepostfix(exp));
    return 0;
}