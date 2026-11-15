#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to return operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix expression to postfix notation
void infixToPostfix(char* infix, char* postfix) {
    char stack[100];
    int top = -1, k = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        // If the character is an operand, add it to postfix string
        if (isalnum(c)) {
            postfix[k++] = c;
        } 
        // If '(', push to stack
        else if (c == '(') {
            stack[++top] = c;
        } 
        // If ')', pop and output until '(' is encountered
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            if (top != -1) top--; // Pop '('
        } 
        // An operator is encountered
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    
    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';
}

// Function to generate Three-Address Code (TAC) from postfix expression
void generateTAC(char* postfix) {
    char stack[100][10];
    int top = -1;
    int tempCount = 1;
    char temp[10], op1[10], op2[10];

    printf("\n--- Generated Three-Address Code (TAC) ---\n");
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        
        // If operand, push onto stack
        if (isalnum(c)) {
            char operand[2] = {c, '\0'};
            strcpy(stack[++top], operand);
        } 
        // If operator, pop two operands, create temporary variable, and print TAC instruction
        else {
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            sprintf(temp, "t%d", tempCount++);
            printf("%s = %s %c %s\n", temp, op1, c, op2);
            
            // Push the temporary variable back onto the stack
            strcpy(stack[++top], temp);
        }
    }
    
    // Final result assignment (optional, if evaluating full expression assignment)
    printf("Result stored in: %s\n", stack[top]);
}

int main() {
    char infix[100], postfix[100];
    
    printf("Enter an arithmetic expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    
    generateTAC(postfix);
    
    return 0;
}
/*
Implement infix to postfix conversion and generate Three-Address Code (TAC)

Enter an arithmetic expression (e.g., a+b*c): a+b*c/d-e*f/g
Postfix Expression: abc*d/+ef*g/-

--- Generated Three-Address Code (TAC) ---
t1 = b * c
t2 = t1 / d
t3 = a + t2
t4 = e * f
t5 = t4 / g
t6 = t3 - t5
Result stored in: t6
*/