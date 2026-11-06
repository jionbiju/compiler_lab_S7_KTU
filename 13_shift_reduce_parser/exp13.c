#include <stdio.h>
#include <string.h>

int i = 0, j = 0, c = 0;
char input[30], stack[30];

void check() {
    // Check for E -> i
    if (stack[i] == 'i') {
        stack[i] = 'E';
        printf("$%-15s %-15s Reduce E->i\n", stack, &input[j + 1]);
        check(); 
    }
    
    // Check for E -> E+E
    if (i >= 2 && stack[i - 2] == 'E' && stack[i - 1] == '+' && stack[i] == 'E') {
        stack[i - 2] = 'E';
        stack[i - 1] = '\0';
        stack[i] = '\0';
        i = i - 2; // Update top of stack pointer
        printf("$%-15s %-15s Reduce E->E+E\n", stack, &input[j + 1]);
        check();
    }
    
    // Check for E -> E*E
    if (i >= 2 && stack[i - 2] == 'E' && stack[i - 1] == '*' && stack[i] == 'E') {
        stack[i - 2] = 'E';
        stack[i - 1] = '\0';
        stack[i] = '\0';
        i = i - 2; // Update top of stack pointer
        printf("$%-15s %-15s Reduce E->E*E\n", stack, &input[j + 1]);
        check();
    }

    //Check for E -> (E)
    if(i>=2 && stack[i-2] == '(' && stack[i-1] == 'E' && stack[i] == ')') {
        stack[i-2]='E';
        stack[i-1]='\0';
        stack[i]='\0';
        i-=2;
        printf("$%-15s %-15s Reduce E->(E)\n",stack, &input[j+1]);
        check();

    }
}

int main() {
    printf("GRAMMAR:\n");
    printf("E -> E+E \n");
    printf("E -> E*E \n");
    printf("E -> (E) \n");
    printf("E -> i \n\n");

    printf("Enter the input string (e.g., i+i*i): ");
    scanf("%s", input);
    c = strlen(input);
    
    // Append '$' to the end of the input
    strcat(input, "$");

    printf("\n%-16s %-15s %s\n", "Stack", "Input", "Action");
    printf("--------------------------------------------------\n");
    
    // Initial state
    printf("$%-15s %-15s \n", "", input);

    // Shift loop
    for (i = 0, j = 0; j < c; i++, j++) {
        stack[i] = input[j];
        stack[i + 1] = '\0';
        
        // Print shift action
        printf("$%-15s %-15s Shift\n", stack, &input[j + 1]);
        
        // Check for possible reductions after shifting
        check();
    }

    if (stack[0] == 'E' && stack[1] == '\0') {
        printf("\nString Accepted.\n");
    } else {
        printf("\nString Rejected.\n");
    }

    return 0;
}
/*
construct a shift reduce parser for a given language 
OUTPUT 1:
GRAMMAR:
E -> E+E
E -> E*E
E -> (E)
E -> i

Enter the input string (e.g., i+i*i): (i+i)*i

Stack            Input           Action
--------------------------------------------------
$                (i+i)*i$
$(               i+i)*i$         Shift
$(i              +i)*i$          Shift
$(E              +i)*i$          Reduce E->i
$(E+             i)*i$           Shift
$(E+i            )*i$            Shift
$(E+E            )*i$            Reduce E->i
$(E              )*i$            Reduce E->E+E
$(E)             *i$             Shift
$E               *i$             Reduce E->(E)
$E*              i$              Shift
$E*i             $               Shift
$E*E             $               Reduce E->i
$E               $               Reduce E->E*E

String Accepted.

OUTPUT 2:
GRAMMAR:
E -> E+E
E -> E*E
E -> (E)
E -> i

Enter the input string (e.g., i+i*i): i++i

Stack            Input           Action
--------------------------------------------------
$                i++i$
$i               ++i$            Shift
$E               ++i$            Reduce E->i
$E+              +i$             Shift
$E++             i$              Shift
$E++i            $               Shift
$E++E            $               Reduce E->i

String Rejected.
*/