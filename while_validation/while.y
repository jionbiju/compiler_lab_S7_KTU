%{
#include <stdio.h>
int yylex();
void yyerror(const char *s);
%}

%token ID NUM WHILE RELOP

%%
S: WHILE '(' C ')' '{' STM '}'  {printf("Valid while statement\n");};
C: ID RELOP ID
    |ID RELOP NUM
    |ID
    ;
STM: ID '=' ID ';'
    | ID '=' NUM ';'
    ;
%%

void yyerror(const char *s){
    printf("Invalid while statement\n");
    return;
}
int main(){
    printf("Enter a while statement\n");
    yyparse();
    return 0;
}

/*
Write a YACC program for WHILE validation.
OUTPUT
Enter a while statement
while (a<10) { a = 9}
Invalid while statement

Enter a while statement
while(a<10)
{
    a=5;
}
Valid while statement
*/