%{
    #include <stdio.h>
%}

%%
abc {printf("ABC");}
.|\n {printf("%s",yytext);}
%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter a text:\n");
    yylex();
    return 0;
}

/*
Write a LEX Program to convert the substring abc to ABC from the given input string
OUTPUT
Compiler_Lab_S7/4_lex_subString$ flex 4_lex_subString.l
Compiler_Lab_S7/4_lex_subString$ gcc lex.yy.c -ll
Compiler_Lab_S7/4_lex_subString$ gcc lex.yy.c
Compiler_Lab_S7/4_lex_subString$ ./a.out
Enter a text:
Hello this is abc from abjhabcbc
Hello this is ABC from abjhABCbc
*/