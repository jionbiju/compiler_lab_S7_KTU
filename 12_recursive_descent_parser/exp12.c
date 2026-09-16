#include <stdio.h>
char input[20];
int i=0;
int flag=0;

void E();
void EP();
void T();
void TP();
void F();

void E(){
    T();
    EP();
}
void EP(){
    if(input[i] == '+'){
        i++;
        T();
        EP();
    }
}
void T(){
    F();
    TP();
}
void TP(){
    if(input[i]=='*'){
        i++;
        F();
        TP();
    }
}
void F(){
    if(input[i]=='i'){
        i++;
    }else if(input[i] == '('){
        i++;
        E();
        if(input[i] == ')'){
            i++;
        }else{
            flag=1;
        }
    }
    else{
        flag=1;
    }
}

int main(){
    printf("Enter a expression\n");
    scanf("%s",input);
    E();
    if(input[i] == '\0' && flag == 0){
        printf("String Accepted.\n");
    }
    else{
        printf("String Rejected\n");
    }
    return 0;
}
/*
Design and implement a recursive descent parser for a given grammar
Grammer
E => TE'
E' => +TE' | epsillon
T => FT'
T' => *FT' | epsillon
F => i | (E)    
OUTPUT
PS G:\Jion Projects\Compiler_Lab_S7\12_recursive_descent_parser> ./a.exe
Enter a expression
i+i
String Accepted.
PS G:\Jion Projects\Compiler_Lab_S7\12_recursive_descent_parser> ./a.exe
Enter a expression
i++*i
String Rejected
PS G:\Jion Projects\Compiler_Lab_S7\12_recursive_descent_parser>                                         
*/