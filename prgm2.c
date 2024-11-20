#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int F(char);
int G(char);
void infix_postfix(char infix[], char postfix[]);

int F(char Sym)
{
    switch(Sym)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^':
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;  // for operands
    }
}

int G(char Sym)
{
    switch(Sym)
    {
        case '+':
        case '-': return 1;
        case '*': 
        case '/': return 3;
        case '^': 
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;  // for operands
    }
}

void infix_postfix(char infix[], char postfix[])
{
    int top = -1, i, j = 0;
    char stack[20], Sym;
    
    stack[++top] = '#'; 
    for(i = 0; i < strlen(infix); i++)
    {
        Sym = infix[i];  
        
        while(F(stack[top]) > G(Sym))
            postfix[j++] = stack[top--];  // Pop the stack and append to postfix
        
        if(F(stack[top]) != G(Sym))  // If not the same precedence operator
            stack[++top] = Sym;  // Push the current operator onto the stack
        else
            top--;  // If it's a closing parenthesis, pop the stack
    }
    
    // Pop all remaining operators from the stack
    while(stack[top] != '#')
        postfix[j++] = stack[top--];
    
    postfix[j] = '\0';  // Null terminate the postfix string
}

int main()
{
    char postfix[20], infix[20];
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    
    infix_postfix(infix, postfix);
    
    printf("The postfix expression is: ");
    printf("%s\n", postfix);
    
    return 0;
}

