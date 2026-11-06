#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Instruction {
    char res[10];
    char arg1[10];
    char op[10];
    char arg2[10];
} arr[10];

int main() {
    int n, i, j;
    
    printf("Enter number of instructions: ");
    scanf("%d", &n);
    
    printf("\nEnter instructions (Format: result arg1 operator arg2)\n");
    printf("Note: If it's a simple assignment like x=5, enter: x 5 - -\n\n");
    
    for(i = 0; i < n; i++) {
        scanf("%s %s %s %s", arr[i].res, arr[i].arg1, arr[i].op, arr[i].arg2);
    }
    
    for(i = 0; i < n; i++) {
        if(strcmp(arr[i].op, "-") == 0 && strcmp(arr[i].arg2, "-") == 0 && isdigit(arr[i].arg1[0])) {
            
            for(j = i + 1; j < n; j++) {
                
                if(strcmp(arr[j].arg1, arr[i].res) == 0) {
                    strcpy(arr[j].arg1, arr[i].arg1);
                }
                
                if(strcmp(arr[j].arg2, arr[i].res) == 0) {
                    strcpy(arr[j].arg2, arr[i].arg1);
                }
            }
        }
    }
    
    printf("\n--- Optimized Code ---\n");
    for(i = 0; i < n; i++) {
        if(strcmp(arr[i].op, "-") == 0 && strcmp(arr[i].arg2, "-") == 0) {
            printf("%s = %s\n", arr[i].res, arr[i].arg1);
        } else {
            printf("%s = %s %s %s\n", arr[i].res, arr[i].arg1, arr[i].op, arr[i].arg2);
        }
    }
    
    return 0;
}
/*
OUTPUT
Enter number of instructions: 4

Enter instructions (Format: result arg1 operator arg2)
Note: If it's a simple assignment like x=5, enter: x 5 - -

a 20 - -
b a - 10
c 8 - -
d c * a

--- Optimized Code ---
a = 20
b = 20 - 10
c = 8
d = 8 * 20
*/