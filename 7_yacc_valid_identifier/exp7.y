%{
    #include <stdio.h>
    int yylex();
    void yyerror(const char *s);
%}

%token letter digit

%%
S:letter E;
E:letter E
 |digit E
 |
 ;
%%
void yyerror(const char *s){
    printf("Not a identifier\n");
}
int main(){
    printf("Enter a identifier:\n");
    if(yyparse()==0)
        printf("Valid Identifier\n");
    return 0;
}
/*
Generate a YACC specification to recognize a valid identifier which starts with a
letter followed by any number of letters or digits.
OUTPUT
Compiler_Lab_S7/7_yacc_valid_identifier$ yacc -d exp7.y
Compiler_Lab_S7/7_yacc_valid_identifier$ flex exp7.l
Compiler_Lab_S7/7_yacc_valid_identifier$ gcc y.tab.c lex.yy.c -ll
Compiler_Lab_S7/7_yacc_valid_identifier$ ./a.out
Enter a identifier:
number
Valid Identifier
Compiler_Lab_S7/7_yacc_valid_identifier$ ./a.out
Enter a identifier:
_abc123
Valid Identifier
Compiler_Lab_S7/7_yacc_valid_identifier$ ./a.out
Enter a identifier:
4_abc
Not a identifier
Compiler_Lab_S7/7_yacc_valid_identifier$ ./a.out
Enter a identifier:
abc@$@
Not a identifier
*/