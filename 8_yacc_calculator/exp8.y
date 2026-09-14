%{
    #include <stdio.h>
    #include <math.h>
    int yylex();
    void yyerror(const char *s);
%}

%token num alpha
%left '+''-'
%left '*''/'
%right '^' %nonassoc UMINUS

%%
S:E {printf("Result=%d",$1);};
E:E'+'E {$$=$1+$3;}
  |E'-'E {$$=$1-$3;}
  |E'*'E {$$=$1*$3;}
  |E'/'E {$$=$1/$3;}
  |E'^'E {$$=pow($1,$3);}
  |'-'E %prec UMINUS {$$=-$2;}
  |'('E')' {$$=$2;}
  |num {$$=$1;}
  |alpha {$$=$1;}
  ;
%%

void yyerror(const char *s){
    printf("\nInvalid Expression\n");
}
int main(){
    printf("Enter the arithmetic operation:\n");
    yyparse();
    return 0;
}
/*
Implementation of Calculator using LEX and YACC
Compiler_Lab_S7/8_yacc_calculator$ yacc -d exp8.y
Compiler_Lab_S7/8_yacc_calculator$ flex exp8.l
Compiler_Lab_S7/8_yacc_calculator$ gcc y.tab.c lex.yy.c -ll -lm
Compiler_Lab_S7/8_yacc_calculator$ ./a.out
Enter the arithmetic operation:
10+9-(4-2)

Result=17
Compiler_Lab_S7/8_yacc_calculator$ ./a.out
Enter the arithmetic operation:
7**9
Invalid Expression
*/