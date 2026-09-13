%{
    #include <stdio.h>
%}

%%

"//".* {}
"/*"([^*]|\*+[^*/])*\*+"/" {}
"int"|"float"|"char"|"double"|"if"|"else"|"while"|"for"|"return"|"void" {printf("%s -> keyword\n",yytext);}

[0-9]+\.[0-9]+ {printf("%s -> Float\n", yytext);}

[0-9]+ { printf("%s -> Integer\n", yytext);}

[a-zA-Z_][a-zA-Z0-9_]* {printf("%s -> Identifier\n", yytext);}

"+"|"-"|"*"|"/"|"="|">="|"<=" {printf("%s -> Operator\n",yytext);}

";"|","|"("|")"|"["|"]"|"{"|"}" {printf("%s -> Special Symbols\n",yytext);}

[ \t\n]+ {}

. {printf("Unknown token: %s\n", yytext);}

%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter a program\n");
    yylex();
    return 0;
}

/*
OUTPUT
Ubunto
Compiler_Lab_S7/2_lexical_analyzer_using_lexTool$ flex 2_lexical_analyzer_using_lexTool.l
Compiler_Lab_S7/2_lexical_analyzer_using_lexTool$ gcc lex.yy.c -ll
Compiler_Lab_S7/2_lexical_analyzer_using_lexTool$ gcc lex.yy.c
Compiler_Lab_S7/2_lexical_analyzer_using_lexTool$ ./a.out
Enter a program
int main(){ int a=10; b= 2; c=a+b-10.2;}
int -> keyword
main -> Identifier
( -> Special Symbols
) -> Special Symbols
{ -> Special Symbols
int -> keyword
a -> Identifier
= -> Operator
10 -> Integer
; -> Special Symbols
b -> Identifier
= -> Operator
2 -> Integer
; -> Special Symbols
c -> Identifier
= -> Operator
a -> Identifier
+ -> Operator
b -> Identifier
- -> Operator
10.2 -> Float
; -> Special Symbols
} -> Special Symbols
*/