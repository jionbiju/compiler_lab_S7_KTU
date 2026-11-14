%{
#include <stdio.h>
int count=0,i;    
%}

%%
"//" {count++;}
"/*"([^*]|\*+[^*/])*\*+"/" {count++;
                            for(i=0; yytext[i] != '\0'; i++){
                                if(yytext[i] == '\n'){
                                    count++;
                                }
                            }}

[ \t\n]+ {}
. {}
%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter the input:\n");
    yylex();
    printf("Number of comment line = %d",count);
    return 0;
}
/*
1.	Write a lex program to count the number of comment lines in a program.
Enter the input:
hello
//this is jb
/*fshdhfsd
idfhhdiafh*/

/*Number of comment line = 3*/