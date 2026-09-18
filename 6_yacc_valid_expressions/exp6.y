%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    void yyerror(const char *s);
%}
%token num id
%left '+''-'
%left '*''/'
%right '^'
%nonassoc UMINUS
%%
E:   E'+'E
    |E'-'E
    |E'*'E
    |E'/'E
    |'('E')'
    |'-'E %prec UMINUS
    |num
    |id
    ;
%%
void yyerror(const char *s){
    printf("invalid expresssion\n");
}
int main(){
    printf("enter the expression\n");
    if(yyparse()==0)
        printf("valid\n");
    return 0;
}

/*
Generate a YACC specification to recognize a valid arithmetic expression that
uses operators +, – , *,/ and parenthesis
OUTPUT
Compiler_Lab_S7/6_yacc_valid_expressions$ yacc -d exp6.y
Compiler_Lab_S7/6_yacc_valid_expressions$ flex exp6.l
Compiler_Lab_S7/6_yacc_valid_expressions$ gcc y.tab.c lex.yy.c -ll
Compiler_Lab_S7/6_yacc_valid_expressions$ ./a.out
enter the expression
(a+b)*c
valid
Compiler_Lab_S7/6_yacc_valid_expressions$ ./a.out
enter the expression
a+*d-c
invalid expresssion
*/