#include <stdio.h>
#include <string.h>

char tac[20][20];

void generateAssembly(int n) {
    printf("\n Generated Assembly Code:\n");
    
    for (int i = 0; i < n; i++) {
        char result[10], arg1[10], arg2[10];
        char op;

        // Parse TAC line of format: result = arg1 op arg2
        int matches = sscanf(tac[i], "%s = %s %c %s", result, arg1, &op, arg2);

        printf("\n Processing TAC: %s\n", tac[i]);

        if (matches == 4) {
            printf("MOV AX, %s\n", arg1);     
            
            switch (op) {
                case '+':
                    printf("ADD AX, %s\n", arg2);
                    break;
                case '-':
                    printf("SUB AX, %s\n", arg2);
                    break;
                case '*':
                    printf("MUL AX, %s\n", arg2);
                    break;
                case '/':
                    printf("DIV AX, %s\n", arg2);
                    break;
                default:
                    printf("Unknown operator\n");
            }
            
            printf("MOV %s, AX\n", result);  // Store result from accumulator
        } 
        else {
            // Simple assignment (e.g., x = t2)
            char src[10];
            sscanf(tac[i], "%s = %s", result, src);
            printf("MOV AX, %s\n", src);
            printf("MOV %s, AX\n", result);
        }
    }
}

int main(){
    int n;
    printf("Enter number of Threes Address Code\n");
    scanf("%d",&n);
    while (getchar() != '\n');
    printf("Enter the TAC statements one by one (e.g., t1 = b * c):\n");
    for(int i=0; i<n; i++){
        fgets(tac[i],sizeof(tac[i]),stdin);
        tac[i][strcspn(tac[i], "\n")] = 0;
    }
    generateAssembly(n);
    return 0;
}

/*
Add assembly code generator for Three-Address Code (TAC) processing
OUTPUT
Enter number of Threes Address Code
3
Enter the TAC statements one by one (e.g., t1 = b * c):
t1 = a - b
t2 = t1 / c
res = t2

 Generated Assembly Code:

 Processing TAC: t1 = a - b
MOV AX, a
SUB AX, b
MOV t1, AX

 Processing TAC: t2 = t1 / c
MOV AX, t1
DIV AX, c
MOV t2, AX

 Processing TAC: res = t2
MOV AX, t2
MOV res, AX*/