#include <stdio.h>
#define MAX 100

char infix[MAX], postfix[MAX];
char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        return stack[top--];
    }
}

int precedence(char c) {
    if (c == '(') 
        return 0;
    if (c == '+' || c == '-') 
        return 1;
    if (c == '*' || c == '/' || c == '%') 
        return 2;
    if (c == '^') 
        return 3;
    return -1;
}

void infixToPostfix() {
    int i = 0, j = 0;
    char c;
    while ((c = infix[i]) != '\0') {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) { 
            postfix[j++] = c;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' that used to run while loop
        } 
        else {   // For operators
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

float evalPostfix() {
    float postfixStack[MAX];
    int top = -1;
    int i = 0;
    float op1, op2, value;
    
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (c >= '0' && c <= '9') {
            postfixStack[++top] = c - '0'; // char to int
        } 
        else {
            op2 = postfixStack[top--];
            op1 = postfixStack[top--];

            switch (c) {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '%':
                    value = (int)op1 % (int)op2;
                    break;
            }
            postfixStack[++top] = value;
        }
        i++;
    }
    return postfixStack[top];
}

int main() {
    printf("Enter infix expression: ");
    gets(infix); 

    infixToPostfix();
    printf("Postfix expression: %s\n", postfix);

    float value = evalPostfix();
    printf("Value of postfix expression is %.2f\n", value);

    return 0;
}
