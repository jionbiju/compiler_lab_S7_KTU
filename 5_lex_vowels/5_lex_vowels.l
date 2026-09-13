%{
    #include <stdio.h>
    int vow=0,cons=0;
%}

%%
[aeiouAEIOU] {vow++;}
[a-zA-Z] {cons++;}
.|\n {}
%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter the Stirng\n");
    yylex();
    printf("Vowels=%d\n",vow);
    printf("Consonants=%d\n",cons);
    return 0;
}
/*
OUTPUT
Write a lex program to find out total number of vowels and consonants fromthe giveninput sting
Compiler_Lab_S7/5_lex_vowels$ flex 5_lex_vowels.l
Compiler_Lab_S7/5_lex_vowels$ gcc lex.yy.c -ll
Compiler_Lab_S7/5_lex_vowels$ gcc lex.yy.c
Compiler_Lab_S7/5_lex_vowels$ ./a.out
Enter the Stirng
hello jion 1234
Vowels=4
Consonants=5
*/