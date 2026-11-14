%{
#include <stdio.h>
int flag=0;
%}

%%
"and" | 
"but" |
"or" | 
"so" {flag = 1;}

[.] {if(flag==1){
        printf("Compound sentence\n");
    }
    else{
        printf("Simple sentence\n");
    }
    flag=0;
    }

[ \t\n] {}
.  {}
%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter a sentence:\n");
    yylex();
    return 0;
}

/*
Write a lex program to recognize whether a given sentence is simple or compound.
Enter a sentence:
Today is monday.
Simple sentence
The car is black and it's BMW.
Compound sentence
*/