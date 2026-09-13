%{
    #include <stdio.h>
    int lines=0,words=0,chara=0;
%}

%%
\n {lines++;chara++;}
[ \t]+ {chara+=yyleng;}
[^ \t\n]+ {words++;chara+=yyleng;}
%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter a text\n");
    yylex();
    printf("\nLines=%d\n",lines);
    printf("Words=%d\n",words);
    printf("Characters=%d\n",chara);
    return 1;
}

/* Write a lex program to display the number of lines, words and characters in an input text.
OUTPUT
Compiler_Lab_S7/3_lex_count$ flex 3_lex_count.l
Compiler_Lab_S7/3_lex_count$ gcc lex.yy.c -ll
Compiler_Lab_S7/3_lex_count$ gcc lex.yy.c
Compiler_Lab_S7/3_lex_count$ ./a.out
Enter a text
hi
hello
this is kerala

Lines=3
Words=5
Characters=24
*/